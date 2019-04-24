#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef struct {
    int data;
    struct Node *link;
} Node;

typedef struct {
    Node *head;
    int n;
} HeaderList;

bool Init(HeaderList *h){
    h->head = (Node *) malloc(sizeof(Node));
    if(!h->head){
        return 0;
    }
    h->head->link = NULL;
    h->n = 0;
    return 1;
}

int Insert(HeaderList *h, int i, int x){
    if(i < -1|| i > h->n - 1){
        return 0;
    }
    Node *temp = h->head;
    for(int j = 0; j <= i; j++){
        temp = temp->link;
    }
    Node *k = (Node *) malloc(sizeof(Node)); 
    k->data = x;
    k->link = NULL;
    temp->link = k;
    h->n++;
    return 1;
}
struct listNode *ListInsertSort(struct listNode *h){
    struct listNode *p;   //原链表的节点指针
    struct listNode *q;         //节点扫描指针，新链表的当前节点
    struct listNode *preq;          //新链表的前一节点
    struct listNode *temp;          //原链表节点的临时指针
    p = h -> next;
    //原链表/无序链表第一个节点作为新链表/有序链表第一个元素，L仍指向第一个节点
    h -> next = NULL;
    //遍历无序链表
    while (p != NULL)
    {
        //在有序链表中寻找合适的插入位置
        preq = NULL;
        temp = p;
        q = h;              //每次都要从有序链表的第一个节点开始扫描
        while ((q != NULL) && (q -> data < temp -> data))
        {
            preq = q;
            q = q -> next;
        }
        //无序链表遍历
        p = p -> next;
        //节点插入到L之前或preq和q之间
        if (q == h)
            h = temp;
        else
            preq -> next = temp;
        temp -> next = q;
        //返回排序后链表首指针
        return h;
    }
}

int main(){
    int n;
    cin>>n;
    Headerhist h;
    Init(&h);
    for(int i = 0; i < n; i++){
        Insert(&h, i, i+1);
    }
}
