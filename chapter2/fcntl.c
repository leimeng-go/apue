#include "apue.h"
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int val;
    if (argc!=2)
       err_quit("usage: fcntl <descriptor#>");
       
    if ((val=fcntl(atoi(argv[1]),F_GETFL,0))<0)
       err_sys("fcntl error for fd %d",atoi(argv[1]));

    switch (val &O_ACCMODE){
    case O_RDONLY:
        printf("read only\n");
        break;

    case O_WRONLY:
        printf("write only\n");

    case O_RDWR:
        printf("read write\n");

    default: 
        err_dump("unknown access mode\n");
    }
    if (val & O_APPEND){
        printf(", append");
    if (val & O_NONBLOCK){
        printf(", nonblocking");
    } 
    if (val & O_SYNC){
        printf(", synchronous writes");

    #if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
      if (val & O_FSYNC)
         printf(", synchronous writes");
    #endif

    putchar('\n');        
    exit(0);    
    }
           
    }   
    exit(0);   
}