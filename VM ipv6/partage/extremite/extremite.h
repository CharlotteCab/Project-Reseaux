#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define PORT 123
#define SORTIE_STANDARD 1

void ext_out ();
void ext_in(int fd); //descripteur fichier source
