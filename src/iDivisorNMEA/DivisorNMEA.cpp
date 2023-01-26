/************************************************************/
/*    NAME: Douglas Lima                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: DivisorNMEA.cpp                                        */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"

//Includes do divisor NMEA

#include "DivisorNMEA.h"
#include "NMEAParserLib/NMEAParser.h"
#include "NMEAParserLib/NMEAParser.cpp"
#include "NMEAParserLib/NMEAParserData.h"
#include "NMEAParserLib/NMEAParserPacket.h"
#include "NMEAParserLib/NMEAParserPacket.cpp"
#include "NMEAParserLib/NMEASentenceBase.h"
#include "NMEAParserLib/NMEASentenceBase.cpp"
#include "NMEAParserLib/NMEASentenceGGA.h"
#include "NMEAParserLib/NMEASentenceGGA.cpp"
#include "NMEAParserLib/NMEASentenceGSA.h"
#include "NMEAParserLib/NMEASentenceGSA.cpp"
#include "NMEAParserLib/NMEASentenceGSV.h"
#include "NMEAParserLib/NMEASentenceGSV.cpp"
#include "NMEAParserLib/NMEASentenceRMC.cpp"
#include "NMEAParserLib/NMEASentenceRMC.h"


using namespace std;

//Variáveis globais para usar no programa e debugs

double lat_gps;
double long_gps;
double speed_gps;
double heading_gps;
char* saida_pCmd;
char* saida_pData;



///
/// \class MyParser
/// \brief child class of CNMEAParser which will redefine notification calls from the parent class.
///
class MyNMEAParser : public CNMEAParser {

	///
	/// \brief This method is called whenever there is a parsing error.
	///
	/// Redefine this method to capture errors.
	///
	/// \param pCmd Pointer to NMEA command that caused the error. Please note that this parameter may be NULL of not completely defined. Use with caution.
	///
	virtual void OnError(CNMEAParserData::ERROR_E nError, char *pCmd) {
		printf("ERROR for Cmd: %s, Number: %d\n", pCmd, nError);
	}

protected:
	///
	/// \brief This method is redefined from CNMEAParserPacket::ProcessRxCommand(char *pCmd, char *pData)
	///
	/// Here we are capturing the ProcessRxCommand to print out status. We also are looking for
	/// the GPGGA message and displaying some data from it.
	///
	/// \param pCmd Pointer to the NMEA command string
	/// \param pData Comma separated data that belongs to the command
	/// \return Returns CNMEAParserData::ERROR_OK If successful
	///
	virtual CNMEAParserData::ERROR_E ProcessRxCommand(char *pCmd, char *pData) {

		// Call base class to process the command
		CNMEAParser::ProcessRxCommand(pCmd, pData);

    // Coloquei para debug
    saida_pCmd = pCmd;
    saida_pData = pData;
		printf("Cmd: %s\nData: %s\n", pCmd, pData);

		// Check if this is the GPGGA command. If it is, then display some data
		if (strstr(pCmd, "GPGGA") != NULL) {
			CNMEAParserData::GGA_DATA_T ggaData;
			if (GetGPGGA(ggaData) == CNMEAParserData::ERROR_OK) {
				//printf("GPGGA Parsed!\n");
				//printf("   Time:                %02d:%02d:%02d\n", ggaData.m_nHour, ggaData.m_nMinute, ggaData.m_nSecond);
				//lat_gps = ggaData.m_dLatitude;
        //long_gps = ggaData.m_dLongitude;
        //printf("   Latitude:            %f\n", ggaData.m_dLatitude);
				//printf("   Longitude:           %f\n", ggaData.m_dLongitude);
				//printf("   Altitude:            %.01fM\n", ggaData.m_dAltitudeMSL);
				//printf("   GPS Quality:         %d\n", ggaData.m_nGPSQuality);
				//printf("   Satellites in view:  %d\n", ggaData.m_nSatsInView);
				//printf("   HDOP:                %.02f\n", ggaData.m_dHDOP);
				//printf("   Differential ID:     %d\n", ggaData.m_nDifferentialID);
				//printf("   Differential age:    %f\n", ggaData.m_dDifferentialAge);
				//printf("   Geoidal Separation:  %f\n", ggaData.m_dGeoidalSep);
				//printf("   Vertical Speed:      %.02f\n", ggaData.m_dVertSpeed);
			}
		} else if (strstr(pCmd, "GPRMC") != NULL) {
      CNMEAParserData::RMC_DATA_T rmcdata;
      if (GetGPRMC(rmcdata) == CNMEAParserData::ERROR_OK) {
        lat_gps = rmcdata.m_dLatitude; // Latitude recebida
        long_gps = rmcdata.m_dLongitude; // Longitude recebida 
        speed_gps = rmcdata.m_dSpeedKnots; // SOG do GPS
        heading_gps = rmcdata.m_dTrackAngle; // Marcação vinda do GPS

      }
    }

		return CNMEAParserData::ERROR_OK;
	}
};

//---------------------------------------------------------
// Constructor()

DivisorNMEA::DivisorNMEA()
{
  //Configs para receber dados da serial
  //endereco_porta_serial = "/dev/pts/3"; // Porta para testes
  //baudrate = 9600;

  //Valores iniciais
  //lat_gps = 0;
  //long_gps = 0;

}

//---------------------------------------------------------
// Destructor

DivisorNMEA::~DivisorNMEA()
{
    close(serial_port);
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool DivisorNMEA::OnNewMail(MOOSMSG_LIST &NewMail)
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

bool DivisorNMEA::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool DivisorNMEA::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  // Crio o buffer para receber as sentenças NMEA
  
  //Dou uma limpada no buffer antes de ler de novo
  memset(&read_buf, '\0', sizeof(read_buf));
  //Faço a leitura das sentenças vindas da porta serial
  //read_buff defini como variável de estado no arquivo '.h'
  int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));

  if (num_bytes < 0) {
      printf("Error reading: %s", strerror(errno));
      return 1;
  }

  //Debug
  Notify("DADOS_RECEBIDOS", read_buf);
  Notify("BYTES_RECEBIDOS", num_bytes);

  // Crio um objeto para parse da msg NMEA
  MyNMEAParser NMEAParser;

  //Processo a sentença
  NMEAParser.ProcessNMEABuffer((char *)read_buf, (int)strlen(read_buf));

  //Atualizo variáveis necessárias para o movimento do navio
  Notify("NAV_LAT", lat_gps);
  Notify("NAV_LONG", long_gps);
  Notify("NAV_SPEED", speed_gps);
  Notify("NAV_HEADING", heading_gps);

  //Reseto os dados
  NMEAParser.ResetData();

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool DivisorNMEA::OnStartUp()
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
  
  registerVariables();	
  //source: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
  // Abro a porta serial
  serial_port = open("/dev/pts/3", O_RDWR); //CONFIG DE PORTA SERIAL AQUI
  // Check for errors
  if (serial_port < 0) {
      printf("Error %i from open: %s\n", errno, strerror(errno));
  }
  //Crio uma struct tty
  struct termios tty;
  
  // Read in existing settings, and handle any error
  if(tcgetattr(serial_port, &tty) != 0) {
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
      return 1;
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO; // Disable echo
  tty.c_lflag &= ~ECHOE; // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
  tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
  // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
  // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

  tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  // Set in/out baud rate to be 9600
  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);

  // Save tty settings, also checking for error
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
      return 1;
  }

  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void DivisorNMEA::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("LINHA_NMEA", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool DivisorNMEA::buildReport() 
{
  #if 0
    m_msgs << "============================================" << endl;
    m_msgs << "File:                                       " << endl;
    m_msgs << "============================================" << endl;

    ACTable actab(4);
    actab << "Alpha | Bravo | Charlie | Delta";
    actab.addHeaderLines();
    actab << "one" << "two" << "three" << "four";
    m_msgs << actab.getFormattedString();

    
  #endif

  ACTable actab(1);
  actab << "Saida_PCmd | Saida_PData | Speed_GPS | Heading_GPS | Lat_Recebida_GPS | Long_Recebida_GPS | String Recebida ";
  actab.addHeaderLines();

  actab << saida_pCmd << saida_pData << speed_gps << heading_gps << lat_gps << long_gps << read_buf;
  m_msgs << actab.getFormattedString();

  return(true);
}




