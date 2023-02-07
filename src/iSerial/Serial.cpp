/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: Serial.cpp                                        */
/*    DATE: 8/11/2022                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "Serial.h"
#include <unistd.h>
#include <cmath>
#include <string>
#include <iostream>


using namespace std;

//---------------------------------------------------------
// Constructor()

Serial::Serial()
{
  //Configurações para envio de dados via Serial
  endereco_porta_serial = "/dev/ttyUSB0"; //Porta real na lancha
  //endereco_porta_serial = "/dev/pts/8"; //Porta simulada para testes
  baudrate = 9600;

  // Valores padrões:
  rudder = 0; //Valor inicial do leme
  thrust = 0; //Valor inicial da máquina
  angulo_leme = 0; //Valor inicial do ângulo do leme
  rudder_convertido = "NULL"; //Valor inicial de leme
  thrust_convertido = "NULL"; //Valor inicial de máquina


  enviaSerial(); //Função que vai fazer o envio dos comandos via Serial
}

//---------------------------------------------------------
// Destructor

Serial::~Serial()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool Serial::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

     if(key == "DESIRED_RUDDER") 
       rudder = msg.GetDouble();
     else if(key == "DESIRED_THRUST")
        thrust = msg.GetDouble();
     else if(key == "ANGULO_LEME")
        angulo_leme = msg.GetDouble();
     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool Serial::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Serial::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  // Pensando em colocar aqui nessa interação o envio direto da porta serial
  // Vou fazer um teste primeiro para saber qual é a saída
  enviaSerial(); // publica as variáveis rudder_convertido e thrust_convertido
  Notify("LEME_SERIAL", rudder_convertido); //Divulga a variável LEME_SERIAL com a string para ser enviada para o PIC 
  Notify("MAQUINA_SERIAL", thrust_convertido); //Divulga a variável MAQUINA_SERIAL com a string para ser enviada para o PIC
  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Serial::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(!m_MissionReader.GetConfiguration(GetAppName(), sParams))
    reportConfigWarning("No config block found for " + GetAppName());

  STRING_LIST::iterator p;
  for(p=sParams.begin(); p!=sParams.end(); p++) {
    string orig  = *p;
    string line  = *p;
    string param = tolower(biteStringX(line, '='));
    string value = line;

    bool handled = false;
    if(param == "foo") {
      handled = true;
    }
    else if(param == "bar") {
      handled = true;
    }

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  bool portOpened = porta_serial.Create(endereco_porta_serial.c_str(), baudrate); //Abertura da porta serial
  registerVariables();	
  enviaSerial(); //Função que faz o envio
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void Serial::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("DESIRED_RUDDER", 0); //Registro da variável do leme
  Register("DESIRED_THRUST", 0); //Registro da variável da máquina
  Register("ANGULO_LEME", 0); //Registro da variável da máquina
}


//------------------------------------------------------------
// Procedure: buildReport()

bool Serial::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(2);
  actab << "angulo_leme | rudder | thrust | Maquina_Serial | Leme_Serial ";
  actab.addHeaderLines();
  actab << angulo_leme << rudder << thrust << thrust_convertido << rudder_convertido;
  m_msgs << actab.getFormattedString();

  return(true);
}


void Serial::enviaSerial() 
{
  //Função para controle já pronta pelo CASNAV
  //Em testes, caso dê ruim só comentar aq

  //Converto o DESIRED_RUDDER da escala de -100 a 100 para -32,5 a 32,5
  //float valor_controle_leme = rudder/3.0769f; //Fiz uma função de 1 grau para conversão de escalas

  Notify("VALOR_CONTROLE_LEME",rudder);

  float erro_Leme = angulo_leme - rudder;

  Notify("ERRO_Leme",erro_Leme);


  //erro e foi calculado sendo atual - setpoint
  float k = 0;//constante de variação tempo(s)/erro(graus);
  //dados de k abaixo foram calculados em testes no seco (sem carga) com motor novo (bomba)
  float k1 = 1.0f;//adjustment factor (ideally should be 1)
  if (erro_Leme < 0)
      k = 0.1495f;
  else
      k = 0.1812f;
  int tempo = round(k*abs(erro_Leme)*10*k1);//times 10 because we need up to decimal of seconds precision
  //UnityEngine.Debug.Log("Tempo Leme: " + tempo + "\n");

  if (tempo > 100) tempo = 99; //O tempo é só dois dígitos
  Notify("TEMPO_LEME",tempo);
  
  //Passo o tempo para string e assim mandar via serial
  std::string tempo_leme = std::to_string(tempo);

  if (tempo_leme.size() == 1) tempo_leme = "0"+tempo_leme; //Caso a string só tenha 1 número - Adiciono zero pela leitura do PIC
  
  // Função para transformar as variáveis DESIRED_RUDDER e DESIRED_THRUST para o envio via serial para o PIC
  // No momento só verifica a variável rudder e thrust e faz a conversão

  //Iteração para o leme
  if (thrust > 0) {
    thrust_convertido = "A1"; // Aumenta a rotação
  }

  //Iteração para a máquina
  if (rudder == 0) {
    rudder_convertido = "L0";
  }
  if (rudder > 0) {
    rudder_convertido = "L0"+tempo_leme+"2"; //Guina tempo calculado para BE
  }
  else if (rudder < 0) {
    rudder_convertido = "L0"+tempo_leme+"1"; //Guina tempo calculado para BB
  }
  
  //Envio dos dados via serial para o leme
  if (angulo_leme < 34 && angulo_leme > -34){ //Modificação no teste da lancha 7fev2023
    if (rudder_convertido == "L0"){
      porta_serial.Write(rudder_convertido.c_str(),2);
    } else {
      porta_serial.Write(rudder_convertido.c_str(),5); //Envia os caracteres para essa porta, coloquei 2 pq nos testes por enquanto só tem 2 caracteres
    }
    
    usleep(tempo*100000); //Delay de tempo calculado - teste - 1000000 equivale a 1 seg.
  }

}


