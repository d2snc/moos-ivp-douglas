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

//Includes do libais
#include "libais/ais.h"

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

//Includes do libais
#include <memory>
#include <string>
#include "libais/ais.h"
#include "libais/ais.cpp"
#include "libais/ais_bitset.cpp"
#include "libais/ais1_2_3.cpp"

//Include do udpclient
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> /* close() */
#include <string.h> /* memset() */

#define LOCAL_SERVER_PORT 10110 //Settings do recebedor UDP
#define MAX_MSG 1000 // Tamanho da mensagem UDP a ser recebida


//Include do geodesy
//Serve para fazer a conversão do LAT/LON recebido pelo AIS para Coordenadas Locais 
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"
#include "../MOOSGeodesy.cpp" // adiciono a funcao de referencia
using namespace std;

//Variáveis globais para usar no programa e debugs

double lat_gps;
double long_gps;
double speed_gps;
double heading_gps;
double nav_depth;
int contador_ais;
long double heading_giro;
long double angulo_leme;
char* saida_pCmd;
char* saida_pData;
int msg_debug;

//Variáveis globais para o receiver UDP
int sd, rc, n;
socklen_t cliLen;
struct sockaddr_in cliAddr, servAddr;
char msg[MAX_MSG];


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
		try {
      CNMEAParser::ProcessRxCommand(pCmd, pData);
    }
    catch (std::system_error& e)
    {
      std::cout << e.what();
    }
    
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
        heading_gps = rmcdata.m_dTrackAngle; // Marcação vinda do GPS - tirei esse e coloquei o heading vindo da giro

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
    //close(serial_port);
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

  memset(msg,0x0,MAX_MSG);

  /* receive message */
  cliLen = sizeof(cliAddr);

  try {
    n = recvfrom(sd, msg, MAX_MSG, 0, 
      (struct sockaddr *) &cliAddr, &cliLen);
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }

  if(n<0) {
    printf(": cannot receive data \n");
    //continue;
  }
    
  /* print received message */
  printf(": from %s:UDP%u : %s \n", 
    inet_ntoa(cliAddr.sin_addr),
    ntohs(cliAddr.sin_port),msg);

  Notify("MSG_UDP",msg); //Declarar uma variável pro MOOSDB

  std::string msg_string = msg;

  //Parser de msg caso seja profundidade
  // Create a string stream to split the input string by commas
  std::stringstream ss(msg_string);
  std::string token;

  // Read the first token (should be "$SDDPT")
  std::getline(ss, token, ',');

  if (token == "$SDDPT") {
      // Read the second token and convert it to a floating-point number
      std::getline(ss, token, ',');
      nav_depth = std::stof(token);

      // Print the extracted nav_depth
      Notify("NAV_PROFUNDIDADE", nav_depth);
  }

  

  // Crio um objeto para parse da msg NMEA
  MyNMEAParser NMEAParser;

  //Processo a sentença
  try {
    NMEAParser.ProcessNMEABuffer((char *)msg, (int)strlen(msg));
  }
  catch (std::system_error& e)
  {
    std::cout << e.what();
  }

  //Publico NAV_X e NAV_Y
  double lat_origin = -22.93335; //ALTERAR AQUI SE MUDAR A CARTA NÁUTICA !!!
  double lon_origin = -43.136666665;
  double nav_x = 0;
  double nav_y = 0;
  m_geodesy.Initialise(lat_origin, lon_origin);
  //m_geodesy.SetRefEllipsoid(23); // Set the ellipsoid to WGS-84
  m_geodesy.LatLong2LocalGrid(lat_gps, long_gps, nav_y, nav_x);

  string x = to_string(nav_x);
  string y = to_string(nav_y);

  Notify("NAV_X", x);
  Notify("NAV_Y", y);

  //Atualizo variáveis necessárias para o movimento do navio
  Notify("NAV_LAT", lat_gps);
  Notify("NAV_LONG", long_gps);
  Notify("NAV_SPEED", speed_gps);
  Notify("NAV_HEADING", heading_giro);
  //para testes
  Notify("GPS_HEADING", heading_gps);
  /*
  if (heading_giro == 0){ //Caso o rumo verdadeiro da giro venha zerada, pego do gps
    Notify("NAV_HEADING", heading_gps); //Alterei para pegar o heading da giro ao invés do gps
  } else {
    Notify("NAV_HEADING", heading_giro);
  }*/

  NMEAParser.ResetData(); //Reseto dados NMEA
  
  //Iteração pelas mensagens e salvo a que contém dados AIS
  
    //msg_debug = msg.substr(0,6);
    //Verifica o inicio da string para fazer o parsing da msg ais
    //PARSING DA MSG AIS
    
  if (msg_string.substr(0,6) == "!AIVDM"){
    try {
      
      const std::string body(libais::GetBody(msg));
      
      const int pad = libais::GetPad(msg);
      //std::string chksum_block = libais::GetNthField(msg, 6, ",");
      //Removendo espacos em branco da string
      //remove(chksum_block.begin(), chksum_block.end(), ' ');
      
      msg_debug = pad;
      
      //std::string chksum_block(libais::GetNthField(msg, 6, ","));
      if (pad >= 0){
        
        std::unique_ptr<libais::Ais1_2_3> msg(new libais::Ais1_2_3(body.c_str(), pad));
        
        //Caso o código MMSI do contato seja diferente do da lancha, adicionar no quadro de contatos
        // MMSI da lancha : 710400014

        //if (msg->mmsi != 710400014 && msg->mmsi != 0) { //Colocar aqui o MMSI da lancha
        
        if (msg->mmsi != 710400014) {
          Notify("MESSAGE_ID", msg->message_id);
          Notify("MESSAGE_MMSI", msg->mmsi);
          Notify("MESSAGE_NAVSTATUS", msg->nav_status);
          Notify("MESSAGE_SOG", msg->sog);
          Notify("MESSAGE_LONGITUDE", msg->position.lng_deg);
          Notify("MESSAGE_LATITUDE", msg->position.lat_deg);
          Notify("MESSAGE_TRUEHEADING", msg->true_heading);

          string msg_lat = to_string(msg->position.lat_deg); //Latitude do ctt
          string msg_lon = to_string(msg->position.lng_deg); //Longitude do ctt
          string msg_spd = to_string(msg->sog); //Veloc do ctt
          string msg_cog = to_string(msg->cog); //Rumo no chão
          string msg_mmsi = to_string(msg->mmsi); //Codigo MMSI
          //msg_debug = msg_mmsi;
          double time = MOOSTime(); //Tempo no MOOS
          string time_string = to_string(time); //Passo o tempo para string

          //Colocar a Latitude e Longitude de Origem
          //!!!!!!! ALTERAR ESSES DADOS SE MUDAR A CARTA NÁUTICA !!!!!!!!!!!!
          double lat_origin = -22.93335;
          double lon_origin = -43.136666665;
          double nav_x = 0;
          double nav_y = 0;

          //Faz a conversão da Lat/Long para coordenadas locais

          m_geodesy.Initialise(lat_origin, lon_origin);
          //m_geodesy.SetRefEllipsoid(23); // Set the ellipsoid to WGS-84
          m_geodesy.LatLong2LocalGrid(msg->position.lat_deg, msg->position.lng_deg, nav_y, nav_x);

          string x = to_string(nav_x);
          string y = to_string(nav_y);
          
          //Coloquei essa lógica para não confundir contato AIS com o navio principal no início da execução
          if (contador_ais > 10) {
            Notify("NODE_REPORT","NAME=contato_"+msg_mmsi+",TYPE=SHIP,TIME="+time_string+",LAT="+msg_lat+",LON="+msg_lon+",SPD="+msg_spd+",HDG="+msg_cog+",LENGTH=3.8,MODE=DRIVE,X="+x+",Y="+y);
          }
          contador_ais +=1;
        }
      }
    }
    catch (std::system_error& e)
    {
      std::cout << e.what();
    }
    } //fechamento do if 
    //Parser do ângulo do leme
    else if (msg_string.substr(0,6) == "$AGRSA") {
      try {
        angulo_leme = stold(libais::GetNthField(msg,1,",")); //Pega o segundo campo da string NMEA
      }
      catch (std::system_error& e)
      {
        std::cout << e.what();
      }
      double ang = angulo_leme;
      Notify("ANGULO_LEME", ang);
      Notify("NAV_YAW", ang); //Variável de retorno do valor do ângulo do leme para o PID
    }
    //Parser do Rumo Verdadeiro dado pela Giro
    else if (msg_string.substr(0,6) == "$GPHDT") {
      try {
        heading_giro = stold(libais::GetNthField(msg,1,",")); //Pega o primeiro campo da string NMEA
      }
      catch (std::system_error& e)
      {
        std::cout << e.what();
      }
    }
  

  //Reseto os dados
  //NMEAParser.ResetData();

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool DivisorNMEA::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  //Cria o socket para receber UDP na porta 10110

  /* socket creation */
  sd=socket(AF_INET, SOCK_DGRAM, 0);
  if(sd<0) {
    printf(" cannot open socket \n");
    exit(1);
  }

  /* bind local server port */
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port = htons(LOCAL_SERVER_PORT);
  rc = bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
  if(rc<0) {
    printf(" cannot bind port number %d \n", 
      LOCAL_SERVER_PORT);
    exit(1);
  }

  printf(" waiting for data on port UDP %u\n", 
    LOCAL_SERVER_PORT);

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

  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void DivisorNMEA::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("LINHA_NMEA", 0);
  //Register("NAV_YAW", 0);
 
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
  actab << "msg_debug | Saida_PCmd | Saida_PData | Speed_GPS | Heading_GPS | Lat_Recebida_GPS | Long_Recebida_GPS | String Recebida ";
  actab.addHeaderLines();

  actab << msg_debug << saida_pCmd << saida_pData << speed_gps << heading_gps << lat_gps << long_gps << read_buf;
  m_msgs << actab.getFormattedString();

  return(true);
}



