#include "Socket.h"


/* 
   char tipo: el tipo de socket que quiere definir
      's' para "stream
      'd' para "datagram"
   bool ipv6: si queremos un socket para IPv6
 */
Socket::Socket( char type, bool ipv6 ){
   int idSocket = -1;
   this->port = default_port;
   if (type == 's') {
      this -> idSocket = socket(AF_INET, SOCK_STREAM,0);
   } else {
      this -> idSocket = socket(AF_INET,SOCK_DGRAM,0);
   }
}


Socket::~Socket(){
   this->Close();
}


void Socket::Close(){
   this->~Socket();

}

/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   int port: ubicacion del proceso, por ejemplo 80
 */
int Socket::Connect( const char * hostip, int port ) {
   struct sockaddr_in  host4;
   memset( (char *) &host4, 0, sizeof( host4 ) );
   host4.sin_family = AF_INET;
   inet_pton( AF_INET, hostip, &host4.sin_addr );
   host4.sin_port = htons( port );
   int st = connect( idSocket, (sockaddr *) &host4, sizeof( host4 ) );
   if ( -1 == st ) {
      perror( "Socket::Connect" );
      exit( 2 );
   }
   return st;
}


/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   char * service: nombre del servicio que queremos acceder, por ejemplo "http"
 */
int Socket::Connect( const char *host, const char *service ) {

   return -1;

}


int Socket::Read( char *text, int len ) {

   return -1;

}


int Socket::Write( const char *text ) {

   return -1;

}


int Socket::Listen( int queue ) {

    return -1;

}


int Socket::Bind( int port ) {

    return -1;

}


Socket * Socket::Accept(){

    return (Socket *) 0;

}


int Socket::Shutdown( int mode ) {

    return -1;

}


void Socket::SetIDSocket(int id){

    idSocket = id;

}
