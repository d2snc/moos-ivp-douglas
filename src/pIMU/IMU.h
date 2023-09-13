/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: IMU.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef IMU_HEADER
#define IMU_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

#include "xbow440/xbow440.h"
using namespace xbow440;


class IMU : public AppCastingMOOSApp
{
 public:
   IMU();
   ~IMU();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   static void ProcessData(const xbow440::ImuData&);

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
