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

class SeqList{
    private:
    int n;
    int maxLength;
    ElemType *element;
    
    public:
    //对顺序表进行预处理，申请数组空间
    status Init(int mSize){
        maxLength = mSize;
        n = 0;
        element = (ElemType *)malloc(sizeof(ElemType)*mSize);
        if(!element){
            return ERROR;
        }
        for(int i = 0; i < mSize; i++){
            element[i] = 0;
        }
        return OK;
    }
    
    //向顺序表中插入值，数组下标表示指数，存储的值表示系数
    status Insert(int co, int ex){
        if(ex >= maxLength){
            return ERROR;
        }
        element[ex] += co;
        return OK;
    }

    //将两个多项式的同幂所对应的值相加，存储到ans顺序表中
    status Add(SeqList M, SeqList *ans){
        int maxn = maxLength > M.maxLength ? maxLength:M.maxLength;
        for(int i = 0; i < maxn; i++){
            ans->element[i] = element[i] + M.element[i];
        }
        return OK;
    }

    //格式化输出顺序表中的多项式
    void Output(){
        int flag = 1;
        int begin = 0;
        for(int i = 0; i < maxLength; i++){
            if(element[i]){
                begin = i;
                break;
            }
        }
        if(!begin){
            cout<<element[0];
        }
        else if(begin == 1){
            if(element[begin] > 1){
                cout<<element[1];
            }
            cout<<ch;
        }
        else {
            if(element[begin] > 1){
                cout<<element[begin];
            }
            cout<<ch<<"^"<<begin;
        }
        for(int i = begin+1; i < maxLength; i++){
            if(i == 1 && element[i]){
                cout<<" + ";
                if(element[i] > 1){
                    cout<<element[i];
                }
                cout<<ch;
                continue;
            }
            if(element[i]){
                cout<<" + ";
                if(element[i] > 1){
                    cout<<element[i];
                }
                cout<<ch<<"^"<<i;
            }
        }
        cout<<endl;
    }

    //释放顺序表占用的内存
    status Destory(){
        (*this).n = 0;
        (*this).maxLength = 0;
        free((*this).element);
    }
};


int main(){
    SeqList L, M, ans;
    L.Init(10000);
    M.Init(10000);
    ans.Init(10000);
    int n;
    cout<<"Please input the length of the first polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        L.Insert(tem1, tem2);
    }
    cout<<"Please input the length of the second polynomial: ";
    cin>>n;
    cout<<"Please input the coef and exp: "<<endl;
    for(int i = 0; i < n; i++){
        int tem1, tem2;
        cin>>tem1>>tem2;
        M.Insert(tem1, tem2);
    }
    cout<<"The first polynomial is: "<<endl;
    L.Output();
    cout<<"The second polynomial is: "<<endl;
    M.Output();
    cout<<"The add of polynomials is: "<<endl;
    L.Add(M, &ans);
    ans.Output();
    L.Destory();
    M.Destory();
    ans.Destory();
    return 0;
}