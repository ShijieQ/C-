#include<stdio.h>
#include<string.h>
#define SIZE 81    //ÿ�е��ַ���������
#define LIM 20     //����ȡ����
#define HALT " "   //�ÿ��ַ�����ֹ����
void stsrt(char *strings[],int num);//�ַ���ָ��������

int main (void){
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct =0;
    int k;
    printf("input up to %d lines, and I will sort them . \n" ,LIM);
    printf("To stop ,press the enter key at a line's start .\n");
    //�����ַ���
    while(ct < LIM && gets(input[ct] )!= NULL && input[ct][0] !='\0')
    {
        ptstr[ct] =input[ct];
        ct++;
    }
    stsrt(ptstr , ct );//����������
    puts ("\n here's the sorted list :\n");
    //��ӡ�������֮���ָ���ַ���
    for (k=0;k <ct ;k++)
    {
        puts(ptstr[k]);
    }
//��ӡ�������֮��������ַ���
    puts ("\n here's the list :\n");

    for (k=0;k <ct ;k++)
    {
        puts(input[k]);
    }
    return 0;
}
//�ַ���ָ��������
void stsrt(char *strings[],int num){
    char *temp;
    int top ,seek;
    //���ַ���ָ���������
    for (top=0; top< num-1;top++ )
        for (seek = top+1;seek<num;seek++)
//���ַ������бȽ�strcmp
            if(strcmp(strings[top] ,strings[seek] ) > 0)
//��������
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek]= temp;
            }
}
