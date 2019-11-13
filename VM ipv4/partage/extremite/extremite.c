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
        sock = socket(AF_INET, SOCK_STREAM, 0);

        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);

        /* Si le client arrive à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR){
          return;
        }

        copie_src_dst(fd, sock);
        /* On ferme la socket précédemment ouverte */
        closesocket(sock);

    }
  }
