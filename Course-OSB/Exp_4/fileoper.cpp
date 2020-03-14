/*fileoper.c 文件操作*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h>

int main()
{
    int fd0, record_len, buff_len, cnt;
    char filename[50], f_buff[2000];

    /*打开当前目录下的一个文件 example.txt，确保存在*/ strcpy(filename, "./example.txt");
    fd0 = open(filename, O_RDWR | O_CREAT, 0644); /*打开文件*/
    if (fd0 < 0)
    {
        printf("Can't create example.txt file!\n");
        exit(0);
    }

    buff_len = 20;
    record_len = 10;

    lseek(fd0, 0, SEEK_SET); /*定位到文件开始位置*/ /*读文件，长度为 record_len * buff_len 的内容到 f_buff 中*/
    cnt = read(fd0, f_buff, record_len * buff_len);
    cnt = cnt / record_len;
    printf("%s\n", f_buff);

    strcpy(f_buff, "1234567890");       /*设置要写入文件的信息*/
    write(fd0, f_buff, strlen(f_buff)); /*写文件*/
    write(fd0, "\n\r", 2);
    close(fd0); /*关闭文件*/
    return 0;
}