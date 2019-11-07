#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
void ext_out (struct sockaddr * addr){
  hSocket = socket( PF_INET, SOCK_DGRAM, 0 );
  addr.sin_family = AF_INET ;
  addr.sin_addr.s_addr = htonl (INADDR_ANY);
  addr.sin_port = htons ((unsigned short)123 ); // Le port d'écoute
  if ( bind( hSocket, (struct sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR )
  {
    printf( "bind() error %d\n", SOCKET_ERRNO );
    return -1;
  }
  char buffer[1024];
  if((n = recvfrom(sock, buffer, sizeof buffer - 1, 0, (SOCKADDR *)&from, &fromsize)) < 0)
  {
    perror("recvfrom()");
    exit(errno);
  }
  buffer[n] = '\0';
  write(1,buffer, sizeof(buffer));


}

void ext_in();
