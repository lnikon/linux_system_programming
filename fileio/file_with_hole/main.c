#include "apue.h" 
#include <fcntl.h> 

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int 
main(void)
{
    int fd;

    if((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("error calling creat");

    if(write(fd, buf1, 10) != 10)
        err_sys("error calling write buf1");

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("error calling lseek");

    if(write(fd, buf2, 10) != 10)
        err_sys("error caling write buf2");



    exit(0);
}
