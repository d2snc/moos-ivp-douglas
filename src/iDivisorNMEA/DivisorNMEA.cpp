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
#include "../../../moos-ivp/MOOS/MOOSGeodesy/libMOOSGeodesy/MOOSGeodesy.cpp"


using namespace std;

//Variáveis globais para usar no programa e debugs

double lat_gps;
double long_gps;
double speed_gps;
double heading_gps;
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

//Variáveis globais para o sender UDP
#define REMOTE_SERVER_PORT 10112 //Porta UDP do OpenCPN para receber
#define IP_ADDRESS "127.0.0.1" //Endereço UDP do OpenCPN para receber

int sd_envio, rc_envio, i;
struct sockaddr_in cliAddr_envio, remoteServAddr;
struct hostent *h;

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
  
  //Envia a mensagem recebida via UDP para a porta 10112 (OpenCPN)
  try {
  rc_envio = sendto(sd_envio, msg, strlen(msg)+1, 0, 
  (struct sockaddr *) &remoteServAddr, 
  sizeof(remoteServAddr));
  }
  catch (std::system_error& e)
    {
      std::cout << e.what();
    }

  printf("Sending data %s \n",msg);

  if(rc_envio<0) {
      printf(": cannot send data \n");
      close(sd_envio);
      exit(1);
  }

  Notify("MSG_UDP",msg); //Declarar uma variável pro MOOSDB

  std::string msg_string = msg;

  //Dou uma limpada no buffer antes de ler de novo
  //memset(&read_buf, '\0', sizeof(read_buf));
  //Faço a leitura das sentenças vindas da porta serial
  //read_buff defini como variável de estado no arquivo '.h'
  //int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
  /*
  if (num_bytes < 0) {
      printf("Error reading: %s", strerror(errno));
      return 1;
  }*/

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

  //Cria o socket para comunicação com o OpenCPN por UDP - Envia na porta 10112

  /* get server IP address (no check if input is IP address or DNS name */
  h = gethostbyname(IP_ADDRESS);
  if(h==NULL) {
    printf("unknown host  \n");
    exit(1);
  }

  printf(": sending data to '%s' (IP : %s) \n", h->h_name,
	 inet_ntoa(*(struct in_addr *)h->h_addr_list[0]));

  remoteServAddr.sin_family = h->h_addrtype;
  memcpy((char *) &remoteServAddr.sin_addr.s_addr, 
	 h->h_addr_list[0], h->h_length);
  remoteServAddr.sin_port = htons(REMOTE_SERVER_PORT);

  /* socket creation */
  sd_envio = socket(AF_INET,SOCK_DGRAM,0);
  if(sd_envio<0) {
    printf(" cannot open socket \n");
    exit(1);
  }
  
  /* bind any port */
  cliAddr_envio.sin_family = AF_INET;
  cliAddr_envio.sin_addr.s_addr = htonl(INADDR_ANY);
  cliAddr_envio.sin_port = htons(0);
  
  rc_envio = bind(sd_envio, (struct sockaddr *) &cliAddr_envio, sizeof(cliAddr_envio));
  if(rc_envio<0) {
    printf(": cannot bind port\n");
    exit(1);
  }

  //Cria o socket para receber UDP na porta 10111

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
  //source: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
  // Abro a porta serial
  serial_port = open("/dev/pts/6", O_RDWR); //CONFIG DE PORTA SERIAL AQUI
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
  actab << "msg_debug | Saida_PCmd | Saida_PData | Speed_GPS | Heading_GPS | Lat_Recebida_GPS | Long_Recebida_GPS | String Recebida ";
  actab.addHeaderLines();

  actab << msg_debug << saida_pCmd << saida_pData << speed_gps << heading_gps << lat_gps << long_gps << read_buf;
  m_msgs << actab.getFormattedString();

  return(true);
}




