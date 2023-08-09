/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: XYZ.cpp                                        */
/*    DATE: December 29th, 1963                             */
/************************************************************/

//App que gera um arquivo xyz na pasta "xyz" da pasta raiz do moos-ivp com data-hora e profundidade dos pontos

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "XYZ.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

// Get the current date and time
auto now = std::chrono::system_clock::now();
std::time_t current_time = std::chrono::system_clock::to_time_t(now);

//---------------------------------------------------------
// Constructor()

XYZ::XYZ()
{
}

//---------------------------------------------------------
// Destructor

XYZ::~XYZ()
{
  //outfile.close();
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool XYZ::OnNewMail(MOOSMSG_LIST &NewMail)
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

     if(key == "NAV_LAT") 
       nav_lat = msg.GetDouble();
     else if(key == "NAV_LONG")
        nav_long = msg.GetDouble();
     else if(key == "NAV_PROFUNDIDADE")
        nav_depth = msg.GetDouble();

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool XYZ::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool XYZ::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  //Abre o arquivo
  std::ofstream outfile(filename, std::ios_base::app);



  //Verifico se a lat/long nova é diferente da anterior
  if (nav_long != last_nav_long || nav_lat != last_nav_lat) {
    outfile << nav_lat << " " << nav_long << " " << nav_depth*(-1) << "\n";

    last_nav_long = nav_long;
    last_nav_lat = nav_lat; 
    std::cout << "Data appended to the global output file." << std::endl;
    
  } else {
      std::cout << "Data not appended as lat and long are the same." << std::endl;
  }

  std::cout << "nav_lat: " << nav_lat << ", nav_long: " << nav_long << ", nav_depth: " << nav_depth*(-1) << std::endl;
  outfile.close();


  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool XYZ::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(!m_MissionReader.GetConfiguration(GetAppName(), sParams))
    reportConfigWarning("No config block found for " + GetAppName());


  // Specify the folder path and construct the full filename
  std::string folder_path = "/home/moos-ivp-douglas/log/log_xyz/";
  std::stringstream filename_ss;
  filename_ss << folder_path << "output_" << std::put_time(std::localtime(&current_time), "%Y%m%d_%H%M%S") << ".xyz";
  filename = filename_ss.str();


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


  registerVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void XYZ::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("NAV_LAT", 0);
  Register("NAV_LONG", 0);
  Register("NAV_PROFUNDIDADE", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool XYZ::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(4);
  actab << "Latitude | Longitude | Profundidade ";
  actab.addHeaderLines();
  actab << nav_lat << nav_long << nav_depth;
  m_msgs << actab.getFormattedString();

  return(true);
}




