#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_length 50  //名字最大长度
#define LINE_length 100 //文本行最大长度
typedef struct cc
{
    struct cc *child, *next; //next 指向同辈份的人物
    char Name[];
} JPNode;
void clear(char p[], int n) //清空字符数组 p
{
    while (n-- > 0)
        *p++ = '\0';
}
static JPNode *last = NULL;
static int last_level = 0;
void AddJP(JPNode **head, char const name[], int level)
{
    JPNode **s = head, *r = NULL;
    JPNode *p = (JPNode *)malloc(2 * sizeof(void *) + strlen(name) + 1);
    p->child = p->next = NULL;
    strcpy(p->Name, name);
    if (*s == NULL)
    {
        *s = p;
        last = p;
        return;
    }
    if (level - last_level == 1)
    {
        last->child = p;
        last = p;
        last_level = level;
        return;
    }
    if ((level == last_level) && (*s != NULL))
    {
        last->next = p;
        last = p;
        last_level = level;
        return;
    }
    r = *s; //r 指向家谱树
    last_level = level;
    while (level-- > 0) //找到相同的辈分
    {
        while (r->next != NULL)
            r = r->next;
        r = r->child;
    } //以兄弟连接
    while (r->next != NULL)
        r = r->next;
    r->next = p;
    last = p;
}

void CreatJP(JPNode **head)
{
    char name[NAME_length] = "", line[LINE_length] = "";
    char *p = NULL;
    int level = 0, i = 0; //辈分, 以制表符个数表示
    FILE *fp = NULL;
    fp = fopen("jiapu_data.txt", "r");
    if (fp == NULL)
    {
        printf("open error! \n");
        exit(1);
    }
    while (level = 0, i = 0, fgets(line, LINE_length, fp) != NULL)
    {
        p = line;
        while (*p++ == '\t')
            level++; //计算辈分 , 计算完后 p 指向名字开始处
        while (line[i++] != '\n')
            ;
        line[i - 1] = '\0'; //读入的换行符用字符串结束标识符替换
        strcpy(name, p - 1);
        AddJP(head, name, level);
        clear(name, NAME_length);
        clear(line, LINE_length);
    }
    fclose(fp);
}

void DispJP(JPNode *p) //从 p 指向的结点显示该家族
{
    static int level = 0;
    int i;
    if (p != NULL)
    {
        for (i = 0; i < level; printf("\t"), i++)
            ;
        printf("%s\n", p->Name);
    }
    else
        return;
    level++;
    DispJP(p->child);
    level--;
    DispJP(p->next);
}
////////////////////////////////////////////////////////////////////
///////
/*在家谱中添加新成员， 并追加到文件中*/
int Equal(char const *p, char const q[]) //判断两个字符串是否相等
{
    while (*p++ == *q++)
        if (*p == '\0' && *q == '\0')
            return (1);
    return (0);
}

JPNode *Find_Name(JPNode *s, char *parent) //定位家谱中的成员。 返回其指针(地址)
{
    static JPNode *here = NULL;
    if (s == NULL)
        return here;
    if (Equal(s->Name, parent) == 1)
        return (here = s);
    here = Find_Name(s->child, parent);
    here = Find_Name(s->next, parent);
    return here;
}

void Print_FILE(JPNode *p, FILE *fp)
{
    static int level = 0;
    int i;
    if (p != NULL)
    {
        for (i = 0; i < level; fprintf(fp, "\t"), i++)
            ;
        fprintf(fp, "%s\n", p->Name);
    }
    else
        return;
    level++;
    Print_FILE(p->child, fp);
    level--;
    Print_FILE(p->next, fp);
}

void ADD_number(JPNode *p) //在家谱中添加新成员, 并写入文件
{
    char parent[NAME_length], name[NAME_length];
    FILE *fp = NULL;
    JPNode *here = NULL;
    JPNode *s = (JPNode *)malloc(2 * sizeof(void *) + strlen(name) + 1);
    s->next = s->child = NULL;
    printf("请输入要添加的新成员的双亲姓名: ");
    scanf("%s", parent);
    printf("请输入要添加的新成员的姓名: ");
    scanf("%s", name);
    strcpy(s->Name, name);
    here = Find_Name(p, parent);
    fp = fopen("jiapu_data.txt", "w");
    if (here != NULL) {
        if (here->child == NULL)
            here->child = s;
        else
        {
            here = here->child;
            while (here->next != NULL)
                here = here->next;
            here->next = s;
        }
        Print_FILE(p, fp);
    }
    else {
        Print_FILE(s, fp);
    }
    fclose(fp);
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/*输出指定家庭的所有成员*/
void Dis_Family(JPNode *p)
{
    char name[NAME_length];
    JPNode *here = NULL;
    printf("请输入该家庭的首个成员: ");
    scanf("%s", name);
    here = Find_Name(p, name);
    if (here == NULL)
    {
        printf("无该家庭! \n");
        return;
    }
    printf("\n");
    DispJP(here);
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
/*确定指定成员在家族中的辈份*/
int beifen(JPNode *p, char name[])
{
    static int n = 1;
    static int level = 0;
    if (p == NULL)
        return level;
    if (Equal(p->Name, name) == 1)
        return (level = n);
    n++;
    beifen(p->child, name);
    n--;
    beifen(p->next, name); //向右查询 n 不必加(先加后减) !
    return level;
}

void Bei_Fen(JPNode *p)
{
    char name[NAME_length];
    int n = 0;
    printf("请输入要查明辈分的人的姓名: ");
    scanf("%s", name);
    n = beifen(p, name);
    if (n == 0)
        printf("该家族中无此人! \n");
    else
        printf("\n %s 是 %s 家族中的第%d辈 \n", name, p->Name, n);
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
/*输出指定辈的所有成员*/
void chabei(JPNode *p, int bei)
{
    static int n = 1;
    static int tag = 0;
    if (p == NULL)
        return;
    if (bei == n)
    {
        tag = 1;
        printf("%s ", p->Name);
    }
    n++;
    chabei(p->child, bei);
    n--;
    chabei(p->next, bei); //向右查询 n 不必加(先加后减) !
    if (tag == 0)
        printf("该家族中还没有这一辈呢. . . . \n");
}

void Disp_Pei(JPNode *p)
{
    int bei;
    printf("\n 你想要查看那一辈的成员: ");
    scanf("%d", &bei);
    printf("\n. . . . 该家族中辈分为%d 的成员有. . . . \n\n", bei);
    chabei(p, bei);
    printf("\n");
}

/////////////////////////////////////////////////////////////////
void menu(void)
{
    printf("\n ****************家谱操作菜单****************\n");
    printf("\
* (1) 在家谱中添加新成员， 并追加到文件中。 *\n\
* (2) 输出指定家庭的所有成员。 *\n\
* (3) 确定指定成员在家族中的辈份(第几代) 。 *\n\
* (4) 输出指定辈的所有成员。 *\n\
* (0) 退出操作! *\n\
********************************************\n");
}

int main(void)
{
    JPNode *JP = NULL; //家谱无结点
    char ch = '1', cc;
    CreatJP(&JP);
    while (ch)
    {
        //system("cls");
        menu();
        printf("\n. . . 请选择: ");
        scanf("%c", &ch); //ch=getchar() ;
        switch (ch)
        {
        case '1':
            ADD_number(JP);
            break;
        case '2':
            Dis_Family(JP);
            break;
        case '3':
            Bei_Fen(JP);
            break;
        case '4':
            Disp_Pei(JP);
            break;
        default:
            ch = '\0';
            break;
        }
        getchar();
        while ((cc = getchar()) != '\n')
            ;
    }
    return 0;
}
