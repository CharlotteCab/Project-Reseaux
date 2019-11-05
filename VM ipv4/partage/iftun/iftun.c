#include <stdio.h>
#include "iftun.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void copie_src_dst(int src, int dst){
  int buf[10];
  while(1){
    read(src,buf,sizeof(int));
    write(dst,buf,sizeof(int));
  }
}
