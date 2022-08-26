
/*
 *  Ejemplo de sockets 
 *  Compilar con:
 *     g++ -g Socket.cc ipv4-test.cc -o ipv4-test.out
 *
 */

#include <stdio.h>
#include <string.h>

#include "Socket.h"

int main( int argc, char * argv[] ) {
   const char * os = "http://os.ecci.ucr.ac.cr/";
   const char * osn = "163.178.104.187";
   const char * request = "GET /futbol/2018/ HTTP/1.1\r\nhost: redes.ecci\r\n\r\n";

   Socket s( 's' );	// Create a new stream socket for IPv4
   char a[512];

   s.Connect( osn, 80 );
   s.Write(  request );
   s.Read( a, 512 );
   printf( "%s\n", a);

}
