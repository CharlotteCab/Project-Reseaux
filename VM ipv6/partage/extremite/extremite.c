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
            sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
            sin.sin_family = AF_INET;                 /* AF_INET --> IPv4*/
            sin.sin_port = htons(PORT);               /* Port défini dans .h (précisé dans le sujet: 123) */
            sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

            while(1){
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
                //}
              else{
                  perror("bind");
              }

              char buffer[1024] = {0};
              int n = 0;

              if((n = recv(csock, buffer, sizeof(buffer) - 1, 0)) < 0)
              {
                  perror("recv()");
                  exit(0);
              }

              buffer[n] = '\0';
              write(SORTIE_STANDARD, buffer, sizeof(buffer));


              closesocket(csock);
            }
            closesocket(sock);
        }
        else
            perror("socket");

    }
}
