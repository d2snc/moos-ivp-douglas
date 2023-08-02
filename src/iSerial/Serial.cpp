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
#include <chrono>
#include <thread>



using namespace std;

//---------------------------------------------------------
// Constructor()

Serial::Serial()
{
  //Configurações para envio de dados via Serial

  endereco_porta_serial = "/dev/ttyUSB0"; //Porta real na lancha
  //endereco_porta_serial = "/dev/ttyVIRT0"; //Porta simulada para testes
  baudrate = 9600;

  // Valores padrões:
  rudder = 0; //Valor inicial do leme
  thrust = 0; //Valor inicial da máquina
  feedback_leme = "NULL";

  limite_positivo = 40; //Ângulo máximo do leme
  limite_negativo = -55;

  //Simulador de ângulo do leme
  //angulo_leme = 0; //Começa zerado
  
  thrust_convertido = "NULL"; //Valor inicial de máquina

  erro_maximo_devagar = 2;
  erro_minimo_devagar = -2;
  erro_maximo_rapido = 6;
  erro_minimo_rapido = -6;

}

//---------------------------------------------------------
// Destructor

Serial::~Serial()
{
  enviaSerial("L0"); //Para o leme quando encerra o programa
  std::cout << "Leme a meio" << std::endl;
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

  //Controle pelo erro obtido

  double erro = angulo_leme -rudder;
  Notify("ERRO_LEME", erro);

  //L0 - parado
  //L1 - bombordo
  //L2 - boreste
  //Adicionei ultimo comando para evitar passar de boreste direto para bombordo sem parar

  //Manobrar a dead zone do erro nos condicionais
  if (erro >= erro_maximo_rapido) {
    if ((ultimo_comando == "L1R") || (ultimo_comando == "L1D")){
      enviaSerial("L0");
      if (angulo_leme < limite_negativo){
        enviaSerial("L0");
      } else {
        enviaSerial("L2R");
      }
    } else {
      if (angulo_leme < limite_negativo){
        enviaSerial("L0");
      } else {
        enviaSerial("L2R");
      }
    }
    ultimo_comando = "L2R";
  } else if (erro <= erro_minimo_rapido) {
    if ((ultimo_comando == "L2R") || (ultimo_comando == "L2D")) {
      enviaSerial("L0");
      if (angulo_leme > limite_positivo) {
        enviaSerial("L0");
      } else {
        enviaSerial("L1R");
      }
    } else {
      if (angulo_leme > limite_positivo) {
        enviaSerial("L0");
      } else {
        enviaSerial("L1R");
      }
    }
    ultimo_comando = "L1R";
  } else if ((erro >= erro_maximo_devagar) && (erro < erro_maximo_rapido)) {
    if ((ultimo_comando == "L1R") || (ultimo_comando == "L1D")){
      enviaSerial("L0");
      if (angulo_leme < limite_negativo){
        enviaSerial("L0");
      } else {
        enviaSerial("L2D");
      }
    } else {
      if (angulo_leme < limite_negativo){
        enviaSerial("L0");
      } else {
        enviaSerial("L2D");
      }
    }
    ultimo_comando = "L2D";
  } else if ((erro <= erro_minimo_devagar) && (erro > erro_minimo_rapido)) {
    if ((ultimo_comando == "L2R") || (ultimo_comando == "L2D")) {
      enviaSerial("L0");
      if (angulo_leme > limite_positivo) {
        enviaSerial("L0");
      } else {
        enviaSerial("L1D");
      }
    } else {
      if (angulo_leme > limite_positivo) {
        enviaSerial("L0");
      } else {
        enviaSerial("L1D");
      }
    }
    ultimo_comando = "L1D";
  }
  
  
   else {
    enviaSerial("L0");
    ultimo_comando = "L0";
  }

 

  
  //Simulador do ângulo de leme - COMENTAR NO REAL
  /*if (ultimo_comando == "L1R") { //leme para bombordo
    angulo_leme -=1;
  } else if (ultimo_comando == "L2R") { //leme para boreste
    angulo_leme +=1;
  } else if (ultimo_comando == "L1D") {
    angulo_leme -= 0.5;
  } else if (ultimo_comando == "L2D") {
    angulo_leme += 0.5;
  }*/

   //Notify("ANGULO_LEME", angulo_leme); //para debug
  
  
  //String de comando de máquina 
  //Apenas valores positivos por enquanto
  if ((int(thrust) > 0) && (int(thrust) < 100)) {
    thrust_convertido = "A0"+to_string(int(round(thrust))); //Envia o valor respectivo de máquina
  } else if (int(thrust) <= 0) {
    thrust_convertido = "A000"; //Apenas zera o atuador 
  }

  enviaSerial(thrust_convertido); //Faço envio do comando de maquina para placa

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
  actab << "deploy | feedback_leme | ultimo_comando | thrust_convertido ";
  actab.addHeaderLines();
  actab << deploy << feedback_leme << ultimo_comando << thrust_convertido;
  m_msgs << actab.getFormattedString();

  return(true);
}


void Serial::enviaSerial(std::string sentenca) 
{
  //Envio de feedback do leme para a porta serial
  try {
    porta_serial.Write(sentenca.c_str(),sentenca.size()); //Envia a sentença via serial
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }

  //Delay de 100ms
  std::chrono::milliseconds delay(100);

  std::this_thread::sleep_for(delay);

}


