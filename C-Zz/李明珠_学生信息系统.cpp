#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 1000//根据文本中数据量修改maxn的值。
void Input(struct student s,int n);
void Runmain(student s[],int n);
void Name_num_query(student s[]);
void Age_query(student s[]);
void Class_query(student s[]);
typedef struct student
{
    char name[100];
    char ID[15];
    char sex[5];
    char age[5];
    char Class[20];
}student;
student s[maxn];

void Print()
{
    printf("\n******************************\n\n");
}

void Printmenu()
{
    printf("File read successful.\n");
    printf("Please select the query mode:\n");
    printf("1.Name or number query.\n");
    printf("2.Age range query.\n");
    printf("3.Class query.\n");
    printf("4.Exit.\n");
}

void Name_num_query(student s[])
{
    int flag = 0;
    char Find[100];
    printf("Please input student name or ID:");
    scanf("%s",Find);
    /*学号查询*/
    Print();
    if(Find[0] >= 48 && Find[0] <= 57)
        for(int i = 0; i < maxn; i++)
            if(strcmp(s[i].ID,Find) == 0)
            {
                printf("%s,%s,%s,%s,%s\n",s[i].ID,s[i].name,s[i].sex,s[i].age,s[i].Class);
                flag = 1;
            }
    /*姓名查询*/
    for(int i = 0; i < maxn; i++)
        if(strcmp(s[i].name,Find) == 0)
        {
            printf("%s,%s,%s,%s,%s\n",s[i].ID,s[i].name,s[i].sex,s[i].age,s[i].Class);
            flag = 1;
        }
    if(!flag)
        printf("Not found.\n");
    Print();
}

void Age_query(student s[])
{
    int flag = 0;
    int Find[2];
    printf("Please input the age range(divided by space):");
    scanf("%d%d",&Find[0],&Find[1]);
    if(Find[0] > Find[1])
    {
        int temp;
        temp = Find[0];
        Find[0] = Find[1];
        Find[1] = temp;
    }
    /*年龄范围查询*/
    Print();
    for(int i = 0; i < maxn; i++)
        if(atoi(s[i].age)>=Find[0]&&atoi(s[i].age)<=Find[1])
        {
            printf("%s,%s,%s,%s,%s\n",s[i].ID,s[i].name,s[i].sex,s[i].age,s[i].Class);
            flag = 1;
        }
    if(!flag)
        printf("Not found.\n");
    Print();
}

void Class_query(student s[])
{
    int flag = 0;
    char Find[100];
    printf("Please input student's Class:");
    scanf("%s",Find);
    /*班级查询*/
    Print();
    for(int i = 0; i < maxn; i++)
    {
        if(strcmp(s[i].Class,Find) == 0)
            {
                printf("%s,%s,%s,%s,%s\n",s[i].ID,s[i].name,s[i].sex,s[i].age,s[i].Class);
                flag = 1;
            }
    }
    if(!flag)
        printf("Not found.\n");
    Print();
}

int main()
{
    /*文件打开*/
    int j;
    char str[100];
    FILE *fp;
    fp = fopen("D:\\students.txt","r");
    if(!fp)
    {
        printf("Can not open file.\n");
        exit(1);
    }
    /*从文件中读取数据到结构体对应数组中*/
    for(int i = 0; i < maxn&&!feof(fp); i++)
    {
        int k = 0;
        fgets(str,100,fp);
        for(j = 0; j < strlen(str)&&str[j] != ','; j++)
            s[i].ID[k++] = str[j];
        k = 0;
        for(j = j + 1; j < strlen(str)&&str[j] != ','; j++)
            s[i].name[k++] = str[j];
        k = 0;
        for(j = j + 1; j < strlen(str)&&str[j] != ','; j++)
            s[i].sex[k++] = str[j];
        k = 0;
        for(j = j + 1; j < strlen(str)&&str[j] != ','; j++)
            s[i].age[k++] = str[j];
        k = 0;
        for(j = j + 1; j < strlen(str) - 1&&str[j] != ','; j++)
            s[i].Class[k++] = str[j];
    }

    /*关闭文件*/
    fclose(fp);
    int n;
    do
    {
        /*打印菜单*/
        Printmenu();
        /*选择查询方式*/
        printf("Please input a mode:");
        scanf("%d",&n);
        if(n>=1&&n<=4)
            Runmain(s,n);
        else
            printf("Error input,please input your choice again!\n");
    }while(n != 4);
/*    for(int i = 0; i < maxn; i++)
        printf("%s,%s,%s,%s,%s\n",s[i].ID,s[i].name,s[i].sex,s[i].age,s[i].Class); */
    return 0;
}

void Runmain(student s[],int n)
{
    switch(n)
    {
        case 1:
            Name_num_query(s);
            break;
        case 2:
            Age_query(s);
            break;
        case 3:
            Class_query(s);
            break;
        case 4:
            break;
    }
}


