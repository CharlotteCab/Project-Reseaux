#include "extremite.h"


void ext_out (){

    SOCKADDR_IN sin;
    SOCKET sock;
    socklen_t recsize = sizeof(sin);

    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);

    int sock_err;


    int erreur = 0;

    if(!erreur)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0); //

        if(sock != INVALID_SOCKET)
        {

            /* Configuration */
            sin.sin6_addr = in6addr_any;  /* Adresse IP automatique */
            sin.sin6_family = AF_INET6;                 /* AF_INET6 --> IPv6*/
            sin.sin6_port = htons(PORT);               /* Port défini dans .h (précisé dans le sujet: 123) */
            sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));


              if(sock_err != SOCKET_ERROR)
              {

                sock_err = listen(sock, 5);
                if(sock_err != SOCKET_ERROR)
                {

                    csock = accept(sock, (SOCKADDR*)&csin, &crecsize);

                }
                else
                    perror("listen");
              }
              else{
                  perror("bind");
              }
              while(1){
                char buffer[1024] = {0};
                int n = 0;

                if((n = recv(csock, buffer, sizeof(buffer) - 1, 0)) < 0)
                {
                    perror("recv()");
                    exit(0);
                }

                buffer[n] = '\0';
                write(SORTIE_STANDARD, buffer, sizeof(buffer));

              }
              closesocket(csock);
              closesocket(sock);
        }
        else
            perror("socket");

    }
}

void ext_in(int fd){
  int erreur = 0;
  SOCKET sock;
    SOCKADDR_IN sin;

    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET6, SOCK_STREAM, 0);

        /* Configuration de la connexion */
        sin.sin6_family = AF_INET6;
        sin.sin6_port = htons(PORT);
        inet_pton(AF_INET6, "fc00:1234:2::36", &sin.sin6_addr);

        /* Si le client arrive à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR){
          return;
        }

        copie_src_dst(fd, sock);
        /* On ferme la socket précédemment ouverte */
        closesocket(sock);

    }
  }
