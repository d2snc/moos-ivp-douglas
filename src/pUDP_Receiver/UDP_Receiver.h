/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: UDP_Receiver.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef UDP_Receiver_HEADER
#define UDP_Receiver_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class UDP_Receiver : public AppCastingMOOSApp
{
 public:
   UDP_Receiver();
   ~UDP_Receiver();

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

 private: // State variables
};

#endif 
