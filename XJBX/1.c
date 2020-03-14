#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_length 50  //������󳤶�
#define LINE_length 100 //�ı�����󳤶�
typedef struct cc
{
    struct cc *child, *next; //next ָ��ͬ���ݵ�����
    char Name[];
} JPNode;
void clear(char p[], int n) //����ַ����� p
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
    r = *s; //r ָ�������
    last_level = level;
    while (level-- > 0) //�ҵ���ͬ�ı���
    {
        while (r->next != NULL)
            r = r->next;
        r = r->child;
    } //���ֵ�����
    while (r->next != NULL)
        r = r->next;
    r->next = p;
    last = p;
}

void CreatJP(JPNode **head)
{
    char name[NAME_length] = "", line[LINE_length] = "";
    char *p = NULL;
    int level = 0, i = 0; //����, ���Ʊ��������ʾ
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
            level++; //���㱲�� , ������� p ָ�����ֿ�ʼ��
        while (line[i++] != '\n')
            ;
        line[i - 1] = '\0'; //����Ļ��з����ַ���������ʶ���滻
        strcpy(name, p - 1);
        AddJP(head, name, level);
        clear(name, NAME_length);
        clear(line, LINE_length);
    }
    fclose(fp);
}

void DispJP(JPNode *p) //�� p ָ��Ľ����ʾ�ü���
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
/*�ڼ���������³�Ա�� ��׷�ӵ��ļ���*/
int Equal(char const *p, char const q[]) //�ж������ַ����Ƿ����
{
    while (*p++ == *q++)
        if (*p == '\0' && *q == '\0')
            return (1);
    return (0);
}

JPNode *Find_Name(JPNode *s, char *parent) //��λ�����еĳ�Ա�� ������ָ��(��ַ)
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

void ADD_number(JPNode *p) //�ڼ���������³�Ա, ��д���ļ�
{
    char parent[NAME_length], name[NAME_length];
    FILE *fp = NULL;
    JPNode *here = NULL;
    JPNode *s = (JPNode *)malloc(2 * sizeof(void *) + strlen(name) + 1);
    s->next = s->child = NULL;
    printf("������Ҫ��ӵ��³�Ա��˫������: ");
    scanf("%s", parent);
    printf("������Ҫ��ӵ��³�Ա������: ");
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
/*���ָ����ͥ�����г�Ա*/
void Dis_Family(JPNode *p)
{
    char name[NAME_length];
    JPNode *here = NULL;
    printf("������ü�ͥ���׸���Ա: ");
    scanf("%s", name);
    here = Find_Name(p, name);
    if (here == NULL)
    {
        printf("�޸ü�ͥ! \n");
        return;
    }
    printf("\n");
    DispJP(here);
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
/*ȷ��ָ����Ա�ڼ����еı���*/
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
    beifen(p->next, name); //���Ҳ�ѯ n ���ؼ�(�ȼӺ��) !
    return level;
}

void Bei_Fen(JPNode *p)
{
    char name[NAME_length];
    int n = 0;
    printf("������Ҫ�������ֵ��˵�����: ");
    scanf("%s", name);
    n = beifen(p, name);
    if (n == 0)
        printf("�ü������޴���! \n");
    else
        printf("\n %s �� %s �����еĵ�%d�� \n", name, p->Name, n);
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
/*���ָ���������г�Ա*/
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
    chabei(p->next, bei); //���Ҳ�ѯ n ���ؼ�(�ȼӺ��) !
    if (tag == 0)
        printf("�ü����л�û����һ����. . . . \n");
}

void Disp_Pei(JPNode *p)
{
    int bei;
    printf("\n ����Ҫ�鿴��һ���ĳ�Ա: ");
    scanf("%d", &bei);
    printf("\n. . . . �ü����б���Ϊ%d �ĳ�Ա��. . . . \n\n", bei);
    chabei(p, bei);
    printf("\n");
}

/////////////////////////////////////////////////////////////////
void menu(void)
{
    printf("\n ****************���ײ����˵�****************\n");
    printf("\
* (1) �ڼ���������³�Ա�� ��׷�ӵ��ļ��С� *\n\
* (2) ���ָ����ͥ�����г�Ա�� *\n\
* (3) ȷ��ָ����Ա�ڼ����еı���(�ڼ���) �� *\n\
* (4) ���ָ���������г�Ա�� *\n\
* (0) �˳�����! *\n\
********************************************\n");
}

int main(void)
{
    JPNode *JP = NULL; //�����޽��
    char ch = '1', cc;
    CreatJP(&JP);
    while (ch)
    {
        //system("cls");
        menu();
        printf("\n. . . ��ѡ��: ");
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
