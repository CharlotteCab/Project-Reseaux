
#include <stdio.h>
#include "iftun.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void copie_src_dst(int src, int dst){
  char buf[256]={0};
  int cc;
  while(1){
    cc = read(src,buf,sizeof(buf));
    if (cc == 0){
    }else{
      write(dst,buf,cc);
    }
  }
}
