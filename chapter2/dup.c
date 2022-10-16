#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{ 
    int fd=open("test.txt",O_CREAT|O_RDWR|O_TRUNC,0774);
    if (fd<0){
     perror("open error");
     exit(-1);
    }
    int fd2=dup2(fd,fileno(stderr));
    if (fd2<0){
        perror("dup error");
        exit(-1);
    }
    printf("fd=%d,fd2=%d\n",fd,fd2);
    fprintf(stderr,"test stderr\n");

    char buf[128];
    size_t n;

    //从键盘接口输入并写入fd2所指向文件
    while ((n=read(STDERR_FILENO,buf,sizeof(buf)))>0){
        if (write(fd2,buf,n)<0) {
            printf("write error!\n");
            exit(-1);
        }                                                                                                                        
    }

    return 0;
}