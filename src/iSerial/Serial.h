/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: Serial.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef Serial_HEADER
#define Serial_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

#ifdef _WIN32
  #include "MOOS/libMOOS/Utils/MOOSNTSerialPort.h"
#else
  #include "MOOS/libMOOS/Utils/MOOSLinuxSerialPort.h"
#endif


class Serial : public AppCastingMOOSApp
{
 public:
   Serial();
   ~Serial();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

   void enviaSerial(std::string sentenca); //Função que envia os dados via serial para o PIC

 private: // Configuration variables
    std::string endereco_porta_serial;
    int baudrate; // Baudrate a ser usada para envio dos dados na porta serial

 private: // State variables
    #ifdef _WIN32
      CMOOSNTSerialPort porta_serial;
    #else
      CMOOSLinuxSerialPort porta_serial;
    #endif
    double rudder;
    double thrust;
    double angulo_leme;
    double desired_speed;
    double nav_speed;
    double limite_negativo;
    double limite_positivo;
    double erro_maximo_devagar;
    double erro_minimo_devagar;
    double erro_maximo_rapido;
    double erro_minimo_rapido;
    std::string ultimo_comando;
    std::string leme_placa;
    std::string sentenca;
    std::string thrust_convertido;
    std::string deploy;
    std::string return_var;
    std::string feedback_leme;
};

#endif 
