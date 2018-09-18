#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage: ./main <file-name>.txt\n");
        return -1;
    }

    int fd = 0;
    if((fd = open(argv[1], O_RDWR)) < 0)
    {
        printf("unable to open file %s\n", argv[1]);
        return -1;
    }
    
    int buf_size = 24;
    char buf[buf_size];
    if((buf_size = read(fd, (void *)buf, buf_size)) < 0)
    {
        printf("can't read the file %s", argv[1]);
        return -1;
    }

    printf("The content of the file %s is \n%s\n", argv[1], buf);

    close(fd);
    

    return 0;
}
