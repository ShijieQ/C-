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
const char ch = 'x';

typedef struct pNode {
    int coef;
    int exp;
    struct pNode* link;
} pNode;

typedef struct {
    struct pNode *head;
    int n;
} polynominal;

status Init(polynominal *L){
    L->head = (pNode*) malloc(sizeof(pNode));
    if(!L->head){
        return ERROR;
    }
    L->head->link = NULL;
    L->n = 0;
    return OK;
}

status Insert(polynominal *L, int i, ElemType c, ElemType e){
    if(i < -1 || i > L->n-1){
        return ERROR;
    }
    pNode *p = L->head;
    for(int j = 0; j <= i; j++){
        p = p->link;
    }
    pNode *q = new pNode;
    q->coef = c;
    q->exp = e;
    q->link = p->link;
    p->link = q;
    L->n++;
    return OK;
}

pNode* Search(polynominal L, int x){
    pNode *p;
    p = L.head->link;
    for(int j = 0; j < L.n; j++){
        if(p->exp == x){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

status Sort(polynominal *L){
    for(int i = 0; i < L->n-1; i++){
        pNode* p = L->head->link;
        pNode* k = L->head;
        for(int j = 0; j < L->n-1-i; j++){
           // cout<<"Before "<<p->element<<"   "<<j<<endl;
            if(p->exp > p->link->exp){
                pNode* tem = p->link->link;
                k->link = p->link;
                p->link->link = p;
                p->link = tem;
            }
            else{
                p = p->link;
            }
            k = k->link;
            //cout<<p->element<<"   "<<j<<endl;
        }
    }
    return OK;
}

void polCpy(polynominal a, polynominal* ans){
    pNode* p;
    p = a.head->link;
    int i = 0;
    while(p){
        Insert(ans, i-1, p->coef, p->exp);
        i++;
        p = p->link;
    }
}

status Output(polynominal L){
    pNode *p;
    if(!L.n){
        return ERROR;
    }
    p = L.head->link;
    while(p){
        if(p == L.head->link){
            if(p->coef != 1 && p->coef != -1)
                cout<<p->coef;
            if(p->exp == 0){
                if(p->coef == 1)
                    cout<<"1";
                if(p->coef == -1)
                    cout<<"-1";
            }
            else if(p->exp == 1){
                cout<<ch;
            }
            else{
                cout<<ch<<"^"<<p->exp;
            }
        }
        if(p->coef > 0 && p != L.head->link){
            if(p->coef == 1)
                cout<<" + ";
            else
                cout<<" + "<<p->coef;
            if(p->exp != 0 && p->exp != 1)
                cout<<ch<<"^"<<p->exp;
            if(p->exp == 1)
                cout<<ch;
            if(p->coef == 1 && p->exp == 0) 
                cout<<1;
        }
        if(p->coef < 0 && p != L.head->link){
            if(p->coef == -1) 
                cout<<" - ";
            else
                cout<<" - "<<-p->coef;
            if(p->exp != 0 && p->exp != 1) 
                cout<<ch<<"^"<<p->exp;
            if(p->exp == 1)
                cout<<ch;
            if(p->coef == -1 && p->exp == 0) 
                cout<<1;
        }
        p = p->link;
    }
    cout<<endl;
    return OK;
}

void add(polynominal a, polynominal b, polynominal *ans){
    pNode* a1 = a.head->link;
    polCpy(b, ans);
    for(int i = 0; i < a.n; i++){
        pNode *tem;// = new pNode;
        tem = Search(*ans, a1->exp);
        if(tem == NULL){
            Insert(ans, ans->n-1, a1->coef, a1->exp);
        }
        else{
            tem->coef += a1->coef;
        }
        a1 = a1->link;
    }
}

void multiply(polynominal a, polynominal b, polynominal *ans){
    pNode* a1 = a.head->link;
    pNode* b1 = b.head->link;
    for(int i = 0; i < a.n; i++){
        b1 = b.head->link;
        for(int j = 0; j < b.n; j++){
            pNode *tem; //= new pNode;
            tem = Search(*ans, a1->exp+b1->exp);
            if(tem == NULL){
                Insert(ans, ans->n-1, a1->coef*b1->coef, a1->exp+b1->exp);
            }
            else{
                tem->coef += a1->coef*b1->coef;
            }
            b1 = b1->link; 
        }
        a1 = a1->link;
    }
}

void Destory(polynominal *L){
    pNode *p;
    while(L->head->link){
        p = L->head->link->link;
        free(L->head->link);
        L->head->link = p;
    }
}

int main(){
    polynominal L;
    Init(&L);
    polynominal K;
    Init(&K);
    polynominal add_ans;
    Init(&add_ans);
    polynominal multiply_ans;
    Init(&multiply_ans);
    int n;
    cout<<"Please input the length of the first polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        Insert(&L, i-1, tem1, tem2);
    }
    cout<<"Please input the length of the second polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        Insert(&K, i-1, tem1, tem2);
    }
    cout<<"The first polynomial is: "<<endl;
    Sort(&L);
    Output(L);
    cout<<"The second polynomial is: "<<endl;
    Sort(&K);
    Output(K);
    cout<<"The add of polynomials is: "<<endl;
    add(L, K, &add_ans);
    Sort(&add_ans);
    Output(add_ans);
    cout<<"The multiply of polynomials is: "<<endl;
    multiply(L, K, &multiply_ans);
    Sort(&multiply_ans);
    Output(multiply_ans);
    //polCpy(L, &K);
    //Output(K);
    Destory(&L);
    Destory(&K);
    Destory(&add_ans);
    Destory(&multiply_ans);
    return 0;
}