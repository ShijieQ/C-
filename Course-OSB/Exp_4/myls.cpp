/*myls.cpp*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

int main(int argc, char *argv[]) {
    DIR *dirp;
    struct dirent *direntp;
    if ((dirp = opendir(argv[1])) == NULL) {
        fprintf(stderr, "error message:%s\n", strerror(errno));
        return 0;
    }
    while ((direntp = readdir(dirp)) != NULL) {
        printf("%s\n", direntp->d_name);
    }
    closedir(dirp);
    return 0;
}