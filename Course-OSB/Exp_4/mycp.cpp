/*mycp.c*/
#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>

#define BUF_SIZE 1024 * 8

int main(int argc, char **argv) {
    int fds, fdd;
    char buf[BUF_SIZE];

    size_t count = 0;

    fds = open(argv[1], O_RDONLY);
    fdd = open(argv[2], O_WRONLY | O_CREAT);

    if (fds && fdd)
    {
        while ((count = read(fds, buf, sizeof(buf))) > 0)
        {
            write(fdd, buf, count);
        }
    }
    close(fds);
    close(fdd);
}