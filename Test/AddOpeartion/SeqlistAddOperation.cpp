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
    //��˳������Ԥ������������ռ�
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
    
    //��˳����в���ֵ�������±��ʾָ�����洢��ֵ��ʾϵ��
    status Insert(int co, int ex){
        if(ex >= maxLength){
            return ERROR;
        }
        element[ex] += co;
        return OK;
    }

    //����������ʽ��ͬ������Ӧ��ֵ��ӣ��洢��ans˳�����
    status Add(SeqList M, SeqList *ans){
        int maxn = maxLength > M.maxLength ? maxLength:M.maxLength;
        for(int i = 0; i < maxn; i++){
            ans->element[i] = element[i] + M.element[i];
        }
        return OK;
    }

    //��ʽ�����˳����еĶ���ʽ
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

    //�ͷ�˳���ռ�õ��ڴ�
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