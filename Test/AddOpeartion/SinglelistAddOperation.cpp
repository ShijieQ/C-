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

// typedef struct pNode {
//     int coef;
//     int exp;
//     struct pNode* link;
// } pNode;

class polynominal{
    private:
    struct pNode {
        int coef;//存储系数
        int exp;//存储指数
        struct pNode* link;//存储下一个节点的地址
    } *head;
    
    public:
    int n;
    //对单链表进行预处理，申请头部节点
    status Init(){
        head = (pNode*) malloc(sizeof(pNode));
        if(!head){
            return ERROR;
        }
        head->link = NULL;
        n = 0;
        return OK;
    }
    
    //向链表中插入多项式的项
    status Insert(int i, ElemType c, ElemType e){
        if(i < -1 || i > n-1){
            return ERROR;
        }
        pNode *p = head;
        for(int j = 0; j <= i; j++){
            p = p->link;
        }
        pNode *q = new pNode;
        q->coef = c;
        q->exp = e;
        q->link = p->link;
        p->link = q;
        n++;
        return OK;
    }
    
    //查找当前链表中是否存在指数为x的节点
    pNode* Search(int x){
        pNode *p;
        p = head->link;
        for(int j = 0; j < n; j++){
            if(p->exp == x){
                return p;
            }
            p = p->link;
        }
        return NULL;
    }

    //对链表进行指数上升的排序(冒泡排序法)
    status Sort(){
        for(int i = 0; i < n-1; i++){
            pNode* p = head->link;
            pNode* k = head;
            for(int j = 0; j < n-1-i; j++){
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
    
    //复制链表信息到ans链表中
    void polCpy(polynominal* ans){
        pNode* p;
        p = head->link;
        int i = 0;
        while(p){
            ans->Insert(i-1, p->coef, p->exp);
            i++;
            p = p->link;
        }
    }
    
    //输出多项式的信息
    status Output(){
        pNode *p;
        if(!n){
            return ERROR;
        }
        p = head->link;
        while(p){
            if(p == head->link){
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
            if(p->coef > 0 && p != head->link){
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
            if(p->coef < 0 && p != head->link){
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

    //将两个多项式相加，并存储到ans链表中
    void add(polynominal b, polynominal *ans){
        pNode* a1 = head->link;
        b.polCpy(ans);
        for(int i = 0; i < n; i++){
            pNode *tem;// = new pNode;
            tem = ans->Search(a1->exp);
            if(tem == NULL){
                ans->Insert(ans->n-1, a1->coef, a1->exp);
            }
            else{
                tem->coef += a1->coef;
            }
            a1 = a1->link;
        }
    }

    //释放链表内存
    void Destory(){
        pNode *p;
        while(head->link){
            p = head->link->link;
            free(head->link);
            head->link = p;
        }
    }
};

int main(){
    polynominal L;
    L.Init();
    polynominal K;
    K.Init();
    polynominal add_ans;
    add_ans.Init();
    int n;
    cout<<"Please input the length of the first polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        L.Insert(i-1, tem1, tem2);
    }
    cout<<"Please input the length of the second polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        K.Insert(i-1, tem1, tem2);
    }
    cout<<"The first polynomial is: "<<endl;
    L.Sort();
    L.Output();
    cout<<"The second polynomial is: "<<endl;
    K.Sort();
    K.Output();
    cout<<"The add of polynomials is: "<<endl;
    L.add(K, &add_ans);
    add_ans.Sort();
    add_ans.Output();
    L.Destory();
    K.Destory();
    add_ans.Destory();
    return 0;
}