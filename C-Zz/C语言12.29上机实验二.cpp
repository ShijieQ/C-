#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    FILE *fp1;
    char str[1000];
    char str_asc[5];
    fp = fopen("D:\\f1.txt","r");
    fp1 = fopen("f2.txt","w");
    while(!feof(fp))
    {
        fgets(str,1000,fp);
        printf("%s",str);
        for(int i = 0; i < strlen(str); i++)
        {
            if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            {
                sprintf(str_asc,"%d",str[i]);
                fputc(str[i],fp1);
                fputc(' ',fp1);
                fputs(str_asc,fp1);
                fputc(' ',fp1);
            }
        }
    }
}
