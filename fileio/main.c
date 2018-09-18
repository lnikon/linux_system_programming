#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage: main <file-name>.txt");
        return -1;
    }

    const char* path = argv[1];
    int fd = open(path, O_RDWR);
    printf("fd = %d\n", fd);

    close(fd);

    fd = creat("MYFIEL.txt", O_RDWR);
    printf("fd = %d\n", fd);
    close(fd);
    
    fd = open("hello.txt", O_RDWR | O_CREAT | O_TRUNC);
    printf("fd = %d\n", fd);
    close(fd);
}
