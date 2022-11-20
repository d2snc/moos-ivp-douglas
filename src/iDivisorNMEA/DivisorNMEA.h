/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: DivisorNMEA.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef DivisorNMEA_HEADER
#define DivisorNMEA_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

#include <boost/asio.hpp>
#include <string>
#include <iostream>


#ifdef _WIN32
  #include "MOOS/libMOOS/Utils/MOOSNTSerialPort.h"
#else
  #include "MOOS/libMOOS/Utils/MOOSLinuxSerialPort.h"
#endif



class DivisorNMEA : public AppCastingMOOSApp
{
 public:
   DivisorNMEA();
   ~DivisorNMEA();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

 private: // Configuration variables
    int serial_port;
    std::string   endereco_porta_serial;
    char* conteudo_porta_serial;
    int           baudrate;
    

 private: // State variables
    #ifdef _WIN32
      CMOOSNTSerialPort porta_serial;
    #else
      CMOOSLinuxSerialPort porta_serial;
    #endif 
    char read_buf [2048];
    char nmea_data [2048]; //Declarei pela divisão
    
};

#endif 
