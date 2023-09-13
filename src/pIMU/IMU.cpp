/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: IMU.cpp                                        */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include <string>
#include <iostream>
#include <sstream>
#include "MBUtils.h"
#include "ACTable.h"
#include "IMU.h"

#include "xbow440/xbow440.h"
using namespace xbow440;
using namespace std;

//Global variables
double ax;
double ay;
double az;
double rollrate;
double pitchrate;
double yawrate;

//Crio o objeto
XBOW440 my_xbow;


//---------------------------------------------------------
// Constructor()

IMU::IMU()
{
}

//---------------------------------------------------------
// Destructor

IMU::~IMU()
{
}

//---------------------------------------------------------
// Data Handler for IMU

void IMU::ProcessData(const ImuData& data) {
    /*
    cout << "Received data. ax: " << data.ax << " ay: " << 
        data.ay << " az: " << data.az << std::endl;

    cout << "rollrate: " << data.rollrate << " pitchrate: " << 
        data.pitchrate << " yawrate: " << data.yawrate << std::endl;
    */
    
    ax = data.ax;
    ay = data.ay;
    az = data.az;
    yawrate = data.yawrate;
    rollrate = data.rollrate;
    pitchrate = data.pitchrate;

};

//---------------------------------------------------------
// Procedure: OnNewMail()

bool IMU::OnNewMail(MOOSMSG_LIST &NewMail)
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

     if(key == "FOO") 
       cout << "great!";

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool IMU::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool IMU::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  
  //Faço o processamento dos dados
  my_xbow.set_data_handler(ProcessData);

  //Salvo os dados em variáveis do MOOS
  Notify("NAV_ACCEL_X", ax);
  Notify("NAV_ACCEL_Y", ay);
  Notify("NAV_ACCEL_Z", az);
  Notify("GYRO_YAW", yawrate);
  Notify("GYRO_ROLL", rollrate);
  Notify("GYRO_PITCH", pitchrate);

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool IMU::OnStartUp()
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
    if(param == "NAV_ACCEL_X") {
      handled = true;
    }
    else if(param == "NAV_ACCEL_Y") {
      handled = true;
    }
    else if(param == "NAV_ACCEL_Z") {
      handled = true;
    }
    else if(param == "GYRO_YAW") {
      handled = true;
    }
    else if(param == "GYRO_ROLL") {
      handled = true;
    }
    else if(param == "GYRO_PITCH") {
      handled = true;
    }

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  
  registerVariables();	

  //Configs da porta serial da IMU
  int baudrate=38400;
  std::string port = "/dev/ttyUSB0"; //Mudar aq a porta da IMU, coloquei essa pois estava testando

  //Conecto com a IMU
  bool result = my_xbow.Connect(port,baudrate);
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void IMU::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
}


//------------------------------------------------------------
// Procedure: buildReport()

bool IMU::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(4);
  actab << "NAV_ACCEL_X | NAV_ACCEL_Y | NAV_ACCEL_Z | GYRO_YAW | GYRO_ROLL | GYRO_PITCH";
  actab.addHeaderLines();
  actab << ax << ay << az << yawrate << rollrate << pitchrate;
  m_msgs << actab.getFormattedString();

  return(true);
}




