#include<stdio.h>
#include<string.h>
#define SIZE 81    //每行的字符长度限制
#define LIM 20     //最多读取行数
#define HALT " "   //用空字符串终止输入
void stsrt(char *strings[],int num);//字符串指针排序函数

int main (void){
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct =0;
    int k;
    printf("input up to %d lines, and I will sort them . \n" ,LIM);
    printf("To stop ,press the enter key at a line's start .\n");
    //输入字符串
    while(ct < LIM && gets(input[ct] )!= NULL && input[ct][0] !='\0')
    {
        ptstr[ct] =input[ct];
        ct++;
    }
    stsrt(ptstr , ct );//调用排序函数
    puts ("\n here's the sorted list :\n");
    //打印输出排序之后的指针字符串
    for (k=0;k <ct ;k++)
    {
        puts(ptstr[k]);
    }
//打印输出排序之后的数组字符串
    puts ("\n here's the list :\n");

    for (k=0;k <ct ;k++)
    {
        puts(input[k]);
    }
    return 0;
}
//字符串指针排序函数
void stsrt(char *strings[],int num){
    char *temp;
    int top ,seek;
    //对字符串指针进行排序
    for (top=0; top< num-1;top++ )
        for (seek = top+1;seek<num;seek++)
//对字符串进行比较strcmp
            if(strcmp(strings[top] ,strings[seek] ) > 0)
//交换排序
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek]= temp;
            }
}
