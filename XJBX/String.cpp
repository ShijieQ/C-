#include <stdio.h>
#include <stdlib.h>

void *strcat(char *a, char *b)
{

    while (*a++)
        ;

    while (*b)
        *a++ = *b++;
}

int main()
{
    char *a = new char[10];
    char *b = new char[10];
    scanf("%s%s", a, b);
    strcat(a, b);
    printf("%s", a);
    return 0;
}