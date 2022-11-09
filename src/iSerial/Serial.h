/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: Serial.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef Serial_HEADER
#define Serial_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

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

   void enviaSerial(); //Função que envia os dados via serial para o PIC

 private: // Configuration variables

 private: // State variables
    double rudder;
    double thrust;
    std::string rudder_convertido;
    std::string thrust_convertido;
};

#endif 
