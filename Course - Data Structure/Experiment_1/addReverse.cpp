#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int status;
typedef int ElemType;

using namespace std;
const int INF = 0x3f3f3f3f;

typedef struct node {
    ElemType element;
    struct node *link;
}node;

typedef struct {
    struct node *head;
    int n;
}headerList;

status Init(headerList *L){
    L->head = (node*) malloc(sizeof(node));
    if(!L->head){
        return ERROR;
    }
    L->head->link = NULL;
    L->n = 0;
    return OK;
}

status Insert(headerList *L, int i, ElemType x){
    if(i < -1 || i > L->n-1){
        return ERROR;
    }
    node *p = L->head;
    for(int j = 0; j <= i; j++){
        p = p->link;
    }
    node *q = new node;
    q->element = x;
    q->link = p->link;
    p->link = q;
    L->n++;
    return OK;
}

status Delete(headerList *L, int i){
    int j;
    node *p, *q;
    if(!L->n){
        return ERROR;
    }
    if(i < 0 || i > L->n-1){
        return ERROR;
    }
    q = L->head;
    for(j = 0; j < i; j++){
        q = q->link;
    }
    p = q->link;
    q->link = p->link;
    free(p);
    L->n--;
    return OK;
}

status Search(headerList L, int i, ElemType *x){
    node *p;
    if(i < 0 || i > L.n-1){
        return ERROR;
    }
    p = L.head;
    for(int j = 0; j <= i; j++){
        p = p->link;
    }
    *x = p->element;
    return OK;
}

status Output(headerList L){
    node *p;
    if(!L.n){
        return ERROR;
    }
    p = L.head->link;
    while(p){
        cout<<p->element<<" ";
        p = p->link;
    }
    cout<<endl;
    return OK;
}

void Destory(headerList *L){
    node *p;
    while(L->head->link){
        p = L->head->link->link;
        free(L->head->link);
        L->head->link = p;
    }
}

status Reverse(headerList *L){
    if(L->n <= 1){
        return OK;
    }
    node *p = L->head->link;
    node *k = p->link;
    while(k != NULL){
        node *tem = k->link;
        k->link = p;
        p = k;
        k = tem;
    }
    L->head->link->link = NULL;
    L->head->link = p;
    return OK;
}

int main(){
    ElemType x;
    headerList L;
    Init(&L);
    int n;
    cout<<"Please input the length :";
    cin>>n;
    for(int i = 0; i < n; i++){
        int tem1;
        cin>>tem1;
        Insert(&L, i-1, tem1);
    }
    cout<<"The headerlist is: "<<endl;
    Output(L);
    Delete(&L, 0);
    cout<<"After delete, The headerlist is: "<<endl;
    Output(L);
    Search(L, 0, &x);
    cout<<"The 0th element is "<<x<<endl;
    Reverse(&L);
    cout<<"After reverse, The headerlist is: "<<endl;
    // Insert(&L, L.n-1, 50);   For test
    Output(L);
    Destory(&L);
    return 0;
}