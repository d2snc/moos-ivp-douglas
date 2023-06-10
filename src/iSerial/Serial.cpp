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
  //endereco_porta_serial = "/dev/ttyUSB0"; //Porta real na lancha
  endereco_porta_serial = "/dev/pts/5"; //Porta simulada para testes
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
     else if(key == "NAV_YAW")
        angulo_leme = msg.GetDouble();
     else if(key == "DEPLOY")
        deploy = msg.GetString(); 
     else if(key == "RETURN")
        return_var = msg.GetString();
     else if(key == "DESIRED_SPEED")
        desired_speed = msg.GetDouble();
     else if(key == "NAV_SPEED")
        nav_speed = msg.GetDouble();
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
  Register("DEPLOY", 0); //Registro da variável deploy (start no pmarineviewer)
  Register("RETURN", 0); //Registro da variável return (start no pmarineviewer)
  Register("DESIRED_SPEED", 0); //Pega a veloc desejada
  Register("NAV_SPEED", 0); //Veloc do navio dada pelo GPS

}


//------------------------------------------------------------
// Procedure: buildReport()

bool Serial::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(2);
  actab << "deploy | angulo_leme | rudder | thrust | Maquina_Serial | Leme_Serial | Angulo_placa ";
  actab.addHeaderLines();
  actab << deploy << angulo_leme << rudder << thrust << thrust_convertido << rudder_convertido << angulo_convertido;
  m_msgs << actab.getFormattedString();

  return(true);
}


void Serial::enviaSerial() 
{
  //Envia comandos para a placa nova 

  //Cria a string do feedback de leme para enviar para a placa
  if (int(angulo_leme) > 0){
    if (int(angulo_leme) < 10) { //Caso seja só 1 dígito
      angulo_convertido = "P0"+to_string(int(round(angulo_leme)))+ "2"; //Guinando para BE
    } else {
      angulo_convertido = "P"+to_string(int(round(angulo_leme)))+ "2"; //Guinando para BE
    }
    
  } else if (int(angulo_leme) <= 0) {
    if (int(angulo_leme*(-1)) < 10) { //Caso seja só 1 dígito
      angulo_convertido = "P0"+to_string(int(round(angulo_leme*(-1))))+ "1"; //Guinando para BB
    } else {
      angulo_convertido = "P"+to_string(int(round(angulo_leme*(-1))))+ "1"; //Guinando para BB
    }
  } 

  Notify("ANGULO_PLACA", angulo_convertido);

  //Envio de feedback do leme para a porta serial
  try {
    porta_serial.Write(angulo_convertido.c_str(),angulo_convertido.size()); //Envia para a placa nova no USB0
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }

  //String de comando de leme 
  if (int(rudder) > 0) {
    if (int(rudder) < 10) {
      rudder_convertido = "L0"+to_string(int(round(rudder)))+"2"; //Guinando para BE
    } else {
      rudder_convertido = "L"+to_string(int(round(rudder)))+"2"; //Guinando para BE
    }
    
  } else if (int(rudder) <= 0) {
    if (int(rudder*(-1)) < 10) {
      rudder_convertido = "L0"+to_string(int(round(rudder*(-1))))+"1"; //Guinando para BB
      //correção bug
      if (rudder_convertido == "L0-11") {
        rudder_convertido = "L011";
      }
    } else {
      rudder_convertido = "L"+to_string(int(round(rudder*(-1))))+"1"; //Guinando para BB
    }
    
  }

  
  //Envio dos dados via serial para o leme

  try {
    porta_serial.Write(rudder_convertido.c_str(),rudder_convertido.size()); //Envia para a placa do davi no USB0
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }

  //String de comando de máquina 
  //Apenas valores positivos por enquanto
  if ((int(thrust) > 0) && (int(thrust) < 100)) {
    thrust_convertido = "A0"+to_string(int(round(thrust))); //Envia o valor respectivo de máquina
  } else if (int(thrust) <= 0) {
    thrust_convertido = "A000"; //Apenas zera o atuador 
  }

  
  //Envio dos dados via serial para a máquina

  try {
    porta_serial.Write(thrust_convertido.c_str(),thrust_convertido.size()); //Envia para a placa o valor da máquina
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }
  

}


