#include <cmath>
#include <cstdio>
#include <cstdlib>
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

typedef struct {
    int n;
    int maxLength;
    ElemType* element;
} SeqList;

status Init(SeqList *L, int mSize){
    L->maxLength = mSize;
    L->n = 0;
    L->element = (ElemType*)malloc(sizeof(ElemType)*mSize);
    if(!L->element) 
        return ERROR;
    return OK;
}

status Find(SeqList L, int i, ElemType *x){
    if(i < 0 || i > L.n-1)
        return ERROR;
    *x = L.element[i];
    return OK;
}

status Insert(SeqList *L, int i, ElemType x){
    if(i < -1 || i > L->n-1)
        return ERROR;
    if(L->n == L->maxLength)
        return ERROR;
    for(int j = L->n-1; j > i; j--)
        L->element[j+1] = L->element[j];
    L->element[i+1] = x;
    L->n = L->n+1;
    return OK;
}

status Delete(SeqList *L, int i){
    if(i < 0 || i > L->n-1)
        return ERROR;
    if(!L->n)
        return ERROR;
    for(int j = i+1; j < L->n; j++)
        L->element[j-1] = L->element[j];
    L->n--;
    return OK;
}

status Output(SeqList L){
    if(!L.n)
        return ERROR;
    for(int i = 0; i <= L.n-1; i++)
        printf("%d ", L.element[i]);
    printf("\n");
    return OK;
}

void Destory(SeqList *L){
    (*L).n = 0;
    (*L).maxLength = 0;
    free((*L).element);
}

int main(){
    SeqList list;
    Init(&list, 10);
    for(int i = 0; i < 9; i++)
        Insert(&list, i-1, i);
    Output(list);
    Delete(&list, 0);
    Output(list);
    Destory(&list);
    return 0;
}