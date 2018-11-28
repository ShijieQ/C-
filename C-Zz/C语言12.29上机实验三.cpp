#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char ID[20];
    char name[30];
    int age;
    double score;
};typedef struct student student;

void Readout(FILE *fp)
{
    student s;
    fp = fopen("D:\\Info.dat","r");
    if(!fp)
    {
        printf("file error.\n");
        exit(1);
    }
    fread(&s,sizeof(s),1,fp);
    while(!feof(fp))
    {
        printf("%s %s %d %f\n",s.ID,s.name,s.age,s.score);
        fread(&s,sizeof(s),1,fp);
    }
    fclose(fp);
    return;
}

void Sort(student s[],int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(s[i].score < s[j].score)
            {
                student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
    return ;
}
int main()
{
    student s[50];
    int n;//students number
    printf("Enter the sum of students: ");
    scanf("%d",&n);
    printf("Please input student's information:(ID name age score)\n");
    for(int i = 0; i < n; i++)
        scanf("%s %s %d %lf",s[i].ID,s[i].name,&s[i].age,&s[i].score);
    /*´æÈëÎÄ¼þ*/
    FILE *fp;
    fp = fopen("D:\\Info.dat","w");
    if(!fp)
    {
        printf("file error.\n");
        exit(1);
    }
    fwrite(s,sizeof(student),n,fp);
  /*fwrite(s,sizeof(student),n,fp);*/
    fclose(fp);
    Readout(fp);
    Sort(s,n);
    return 0;
}
