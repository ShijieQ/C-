#include <stdio.h>

int main() {
    int p1;
    while ((p1 = fork()) == -1)
        ;
    if (p1 == 0) {
        printf("I am child. pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(5);
        printf("I am child. pid = %d, ppid = %d\n", getpid(), getppid());
    }
    else {
        printf("I am father. pid = %d\n", getpid());
        sleep(1);
        printf("I am father. I am die.\n");
        return 0;
    }
    return 0;
}