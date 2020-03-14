#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define M 100 + 1 // 宏定义， 定义最大名字字母长度

typedef struct elem
{
    char *name;
    char *post;
} element; //双亲孩子表示法

typedef struct tree
{
    element *item;
    int level;
    int childNum;
    struct tree *parent;
    struct tree *nextSibling;
    struct tree *prevSibling;
    struct tree *firstChild;
} Node, Tree; // 实现一个栈， 用于后续操作

typedef struct stack_t
{
    Node **array; // array 是个数组， 其元素为 Node*型指针
    int index;    // 指示栈顶元素
    int size;     // 栈的大小
} STACK;          // 重命名

typedef struct queue_t
{
    Node **array; // array 是个数组， 其内部元素为 Node*型指针
    int head;     // 队列的头
    int tail;     // 队列的尾
    int num;      // 队列中元素的个数
    int size;     // 队列的大小
} QUEUE;          // 这里的栈和队列， 都是用动态数组实现的， 另一种实现方式是用链表

void *util_malloc(int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) // 如果分配失败， 则终止程序
    {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    return ptr; // 分配成功， 则返回
} // 字符串赋值函数

char *util_strdup(char *src)
{
    char *dst = strdup(src);
    if (dst == NULL) // 如果赋值失败， 则终止程序
    {
        printf("Memroy allocation error!\n");
        exit(EXIT_FAILURE);
    } // 赋值成功， 返回
    return dst;
} // 对 fopen 函数封装

FILE *util_fopen(char *name, char *access)
{
    FILE *fp = fopen(name, access);
    if (fp == NULL) // 如果打开文件失败， 终止程序
    {
        printf("Error opening file %s!\n", name);
        exit(EXIT_FAILURE);
    }
    return fp; // 打开成功， 返回
} // 实现一些栈操作

STACK *STACKinit(int size) // 初始化栈大小为 size
{
    STACK *sp;
    sp = (STACK *)util_malloc(sizeof(STACK));
    sp->size = size;
    sp->index = 0;
    sp->array = (Node **)util_malloc(size * sizeof(Node *));
    return sp;
} // 检测栈是否为空

int STACKempty(STACK *sp)
{
    if (sp == NULL || sp->index <= 0) // 空
    {
        return 1;
    }
    else
    {
        return 0;
    } // 压栈操作
}

int STACKpush(STACK *sp, Node *data)
{
    if (sp == NULL || sp->index >= sp->size) // sp 没有被初始化， 或者已满
    {
        return 0; // 压栈失败
    }
    else
    {
        sp->array[sp->index++] = data; // 压栈
        return 1;
    } // 弹栈操作
}

int STACKpop(STACK *sp, Node **data_ptr)
{
    if (sp == NULL || sp->index <= 0) // sp 为初始化， 或者为空没有元素
    {
        return 0;
    }
    else
    {
        *data_ptr = sp->array[--sp->index]; // 弹栈
        return 1;
    } // 将栈消毁
}

void STACKdestroy(STACK *sp)
{
    free(sp->array);
    free(sp);
} // 以上是栈的操作

QUEUE *QUEUEinit(int size)
{
    QUEUE *qp;
    qp = (QUEUE *)util_malloc(sizeof(QUEUE));
    qp->size = size;
    qp->head = qp->tail = qp->num = 0;
    qp->array = (Node **)util_malloc(size * sizeof(Node *));
    return qp;
} // 入队列

int QUEUEenqueue(QUEUE *qp, Node *data)
{
    if (qp == NULL || qp->num >= qp->size) // qp 未初始化或已满
    {
        return 0; // 入队失败
    }
    else
    {
        qp->array[qp->tail] = data;             // 入队， tail 一直指向最后一个元素的下一个位置
        qp->tail = (qp->tail + 1) % (qp->size); // 循环队列
        ++qp->num;
        return 1;
    }
} // 出队列

int QUEUEdequeue(QUEUE *qp, Node **data_ptr)
{
    if (qp == NULL || qp->num <= 0) // qp 未初始化或队列内无元素
    {
        return 0;
    }
    else
    {
        *data_ptr = qp->array[qp->head];        // 出队
        qp->head = (qp->head + 1) % (qp->size); // 循环队列
        --qp->num;
        return 1;
    } // 检测队列是否为空
}
int QUEUEempty(QUEUE *qp)
{
    if (qp == NULL || qp->num <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    } // 销毁队列
}
void QUEUEdestroy(QUEUE *qp)
{
    free(qp->array);
    free(qp);
} // 以上是队列的有关操作实现

element *createElement()
{
    element *temp = (element *)util_malloc(sizeof(element));
    printf("请输入姓名和职业:\r\n");
    temp->name = (char *)util_malloc(M);
    temp->post = (char *)util_malloc(M);
    scanf("%s %s", temp->name, temp->post);
    return temp;
} //初始化族谱

Tree *createTree()
{
    Tree *head = (Tree *)util_malloc(sizeof(Tree));
    head->childNum = 0;
    head->level = 0;
    head->firstChild = head->parent = head->nextSibling = NULL;
    head->item = createElement();
    return head;
}

Node *searchNodeByName(char *name, Tree *tree)
{
    Node *head = tree;
    Node *result = NULL;
    QUEUE *que = QUEUEinit(M);
    QUEUEenqueue(que, head);
    while (QUEUEempty(que) == 0 && result == NULL)
    {
        Node *temp;
        QUEUEdequeue(que, &temp);
        if (strcmp(name, temp->item->name) == 0)
        {
            result = temp;
        }
        else
        {
            temp = temp->firstChild;
            while (temp != NULL)
            {
                QUEUEenqueue(que, temp);
                temp = temp->nextSibling;
            }
        }
    } /*
    if (tree!=NULL)
    {
    if (strcmp(name,tree->item->name) == 0)
    {
    temp = tree;
    }
    else
    {
    while(temp!=NULL&&tree->nextSibling!=NULL){
    temp = searchNodeByName(name,tree->firstChild);
    }
    }
    }*/
    return result;
}

Node *createNode()
{
    Node *temp = (Node *)util_malloc(sizeof(Node));
    temp->childNum = 0;
    temp->level = 0;
    temp->firstChild = temp->parent = temp->nextSibling = temp->prevSibling = NULL;
    temp->item = createElement();
    return temp;
} //插入节点

void insertNode(Tree *tree)
{
    printf("请输入双亲的名字:\r\n");
    char *parentName = (char *)util_malloc(M);
    scanf("%s", parentName);
    Node *parent = searchNodeByName(parentName, tree);
    if (parent != NULL)
    {
        printf("找到双亲 姓名:%s 职位:%s", parent->item->name, parent->item->post);
        Node *child = createNode();
        child->parent = parent;
        if (parent->firstChild == NULL)
        {
            parent->firstChild = child;
        }
        else
        {
            Node *lastChild = parent->firstChild;
            while (lastChild->nextSibling != NULL)
            {
                lastChild = lastChild->nextSibling;
            }
            lastChild->nextSibling = child;
            child->prevSibling = lastChild;
        }
        printf("插入成功\r\n");
    }
    else
    {
        printf("没有找到双亲\r\n");
        system("pause");
    }
    free(parentName);
}

void FreeNode(Node *Node)
{
    free(Node->item->name);
    free(Node->item->post);
    free(Node->item);
    free(Node->firstChild);
    free(Node->parent);
    free(Node->nextSibling);
    free(Node);
} //倒序层次遍历 从右往左 --> 从孩子到父亲

void ReverseTraversal(Node *node, void (*func)(Node *))
{
    STACK *stack = STACKinit(M);
    Node *temp = node;
    if (temp != NULL)
    {
        if (temp->firstChild == NULL && temp->nextSibling == NULL)
        {
            func(temp);
        }
        else
        {
            temp = temp->firstChild;
            while (temp != NULL)
            {
                STACKpush(stack, temp);
                temp = temp->nextSibling;
            }
            while (STACKempty(stack) == 0)
            {
                Node *pop;
                STACKpop(stack, &pop);
                ReverseTraversal(pop, func);
            }
        }
    }
}

void OrderTraversal(Node *node, void (*func)(Node *))
{
    QUEUE *que = QUEUEinit(M);
    Node *head = node;
    QUEUEenqueue(que, head);
    while (QUEUEempty(que) == 0)
    {
        Node *deque;
        QUEUEdequeue(que, &deque);
        func(deque);
        deque = deque->firstChild;
        while (deque)
        {
            QUEUEenqueue(que, deque);
            deque = deque->nextSibling;
        }
    }
}

void delNode(Tree *tree)
{
    printf("请输入要删除的姓名\r\n");
    char *name = (char *)util_malloc(M);
    scanf("%s", name);
    Node *temp = searchNodeByName(name, tree);
    if (temp->nextSibling != NULL && temp->prevSibling != NULL)
    {
        temp->prevSibling->nextSibling = tree->nextSibling;
        temp->nextSibling->prevSibling = temp->prevSibling;
    }
    else if (temp->prevSibling == NULL && temp->nextSibling != NULL)
    {
        temp->parent->firstChild = temp->nextSibling;
        temp->nextSibling->prevSibling = NULL;
    }
    else if (temp->prevSibling != NULL && temp->nextSibling == NULL)
    {
        temp->prevSibling->nextSibling == NULL;
    }
    else if (temp->prevSibling == NULL && temp->nextSibling == NULL)
    {
        temp->parent->firstChild = NULL;
    }
    ReverseTraversal(temp, FreeNode);
    printf("删除成功\r\n");
    free(name);
}

void printNode(Node *node)
{
    printf("%5s", node->item->name);
}

int count(Tree *tree)
{
    int result = 0;
    QUEUE *que = QUEUEinit(M);
    Node *head = tree;
    QUEUEenqueue(que, head);
    while (QUEUEempty(que) == 0)
    {
        Node *deque;
        QUEUEdequeue(que, &deque);
        result++;
        deque = deque->firstChild;
        while (deque)
        {
            QUEUEenqueue(que, deque);
            deque = deque->nextSibling;
        }
    }
    return result;
}

void search(Tree *tree)
{
    printf("请输入节点的名字:\r\n");
    char *parentName = (char *)util_malloc(M);
    scanf("%s", parentName);
    Node *parent = searchNodeByName(parentName, tree);
    if (parent != NULL)
    {
        printf("找到节点 姓名:%s 职位:%s", parent->item->name, parent->item->post);
    }
    else
    {
        printf("查无此人!\r\n");
    }
}

void modify(Tree *tree)
{
    printf("请输入要修改的姓名\r\n");
    char *name = (char *)util_malloc(M);
    scanf("%s", name);
    Node *temp = searchNodeByName(name, tree);
    printf("请输入姓名和职业:\r\n");
    scanf("%s %s", temp->item->name, temp->item->post);
    printf("修改成功\r\n");
}

void searchSiblings(Node *node)
{
    printf("请输入要查找同辈的姓名\r\n");
    char *name = (char *)util_malloc(M);
    scanf("%s", name);
    Node *temp = searchNodeByName(name, node);
    Node *parent = temp->parent;
    Node *siblings = parent->firstChild;
    if (siblings != NULL)
    {
        printf("和你同辈的人有:");
        while (siblings != NULL)
        {
            printf("%2s", siblings->item->name);
            siblings = siblings->nextSibling;
        }
    }
    else
    {
        printf("没有找到同辈\r\n");
    }
}

void getParent(Node *node)
{
    printf("请输入节点的名字:\r\n");
    char *parentName = (char *)util_malloc(M);
    scanf("%s", parentName);
    Node *parent = searchNodeByName(parentName, node);
    parent = parent->parent;
    if (parent != NULL)
    {
        printf("找到祖先 姓名:%s 职位:%s", parent->item->name, parent->item->post);
    }
    else
    {
        printf("查无此人!\r\n");
    }
}

void statistical(Tree *tree)
{
    printf("请输入要查找的职业\r\n");
    char *post = (char *)util_malloc(M);
    scanf("%s", post);
    int result = 0;
    QUEUE *que = QUEUEinit(M);
    Node *head = tree;
    QUEUEenqueue(que, head);
    while (QUEUEempty(que) == 0)
    {
        Node *deque;
        QUEUEdequeue(que, &deque);
        if (strcmp(post, deque->item->post) == 0)
        {
            result++;
        }
        deque = deque->firstChild;
        while (deque)
        {
            QUEUEenqueue(que, deque);
            deque = deque->nextSibling;
        }
    }
    printf("从事%s 的人数共%d", post, result);
}

int main()
{
    printf("欢迎来到建议家谱系统\r\n");
    Tree *tree = createTree();
    printf("家谱初始化成功\r\n");
    system("pause");
    for (;;)
    {
        system("cls");
        printf("请选择所需要的功能\r\n");
        printf("1.添加子孙\r\n");
        printf("2.修改信息\r\n");
        printf("3.删除信息\r\n");
        printf("4.查询信息\r\n");
        printf("5.族谱中集合\r\n");
        printf("6.查找同辈\r\n");
        printf("7.查询上一辈\r\n");
        printf("8.统计总人数\r\n");
        printf("9.统计从事某一种职业的人数\r\n");
        int option = 0;
        fflush(stdin);
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            insertNode(tree);
            system("pause");
            break;
        case 2:
            modify(tree);
            system("pause");
            break;
        case 3:
            delNode(tree);
            system("pause");
            break;
        case 4:
            search(tree);
            system("pause");
            break;
        case 5:
            OrderTraversal(tree, &printNode);
            system("pause");
            break;
        case 6:
            searchSiblings(tree);
            system("pause");
            break;
        case 7:
            getParent(tree);
            system("pause");
            break;
        case 8:
            printf("族谱中总人数%d", count(tree));
            system("pause");
            break;
        case 9:
            statistical(tree);
            system("pause");
            break;
        default:
            printf("暂时没有此功能\r\n");
            system("pause");
        }
    }
    return 0;
}