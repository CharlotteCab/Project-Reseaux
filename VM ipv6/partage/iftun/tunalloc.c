#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include "iftun.h"
#include "../extremite/extremite.h"




int tun_alloc(char *dev)
{
  struct ifreq ifr;
  int fd, err;

  if( (fd = open("/dev/net/tun", O_RDWR)) < 0 ){
    perror("alloc tun");
    exit(-1);
  }

  memset(&ifr, 0, sizeof(ifr));

  /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
   *        IFF_TAP   - TAP device
   *
   *        IFF_NO_PI - Do not provide packet information
   */
  ifr.ifr_flags = IFF_TUN ;
  // | IFF_NO_PI;
  if( *dev )
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);

  if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
    close(fd);
    return err;
  }
  strcpy(dev, ifr.ifr_name);
  return fd;
}

int main (int argc, char** argv){

  int tunfd;
  //printf("Creation de %s\n",argv[1]);
  tunfd = tun_alloc(argv[1]);
  char* in_out = argv[2];
  //printf("Faire la configuration de %s...\n",argv[1]);
  //printf("Appuyez sur une touche pour continuer\n");
  system("./configure-tun.sh");
  if (strcmp(in_out,"0")==0){
    ext_out();
  }else{
    ext_in(tunfd);
  }
  //printf("Interface %s Configuree:\n",argv[1]);
  //system("ip addr");
  printf("Appuyez sur une touche pour terminer\n");
  getchar();

  return 0;
}
