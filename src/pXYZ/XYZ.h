/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: XYZ.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef XYZ_HEADER
#define XYZ_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class XYZ : public AppCastingMOOSApp
{
 public:
   XYZ();
   ~XYZ();

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
  double nav_lat;
  double nav_long;
  double nav_depth;
  double last_nav_long = 0;
  double last_nav_lat = 0;
  std::ofstream outfile;
  std::string filename;

 private: // State variables
};

#endif 
