#include "apue.h"
#include <fcntl.h>

char buf1[]= "abcdefghij";
char buf2[]= "ABCDEFGHIJ";

int main(void)
{
    int fd;
    if ((fd=creat("file.hole",FILE_MODE))<0)
       err_sys("create error");
    if (write(fd,buf1,10)!=10)
       err_sys("buf1 write error");
    // offset now=10,现在偏移量为10

    /*
     whence 绝对偏移量，将该文件的偏移量设置为距文件开始处offset个字符，成功返回新的文件偏移量
    */
    if (lseek(fd,16384,SEEK_SET)==-1)
       err_sys("lseek error");
    // offset now 16384
    
    if (write(fd,buf2,10)!=10)
       err_sys("buf2 write error");
    // offset now 16394
    exit(0);   
}