#include<cstring>
#include<iostream>
#include<algorithm>
#define ElemType char

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;

class stack{
    private:
        int top;
        int maxSize;
        ElemType *element;
    public:
        stack(){
            maxSize = maxn-1;
            element = (ElemType *)malloc(sizeof(ElemType)*maxn);
            top = -1;
        }

        stack(int mSize){
            maxSize = mSize-1;
            element = (ElemType *)malloc(sizeof(ElemType)*mSize);
            top = -1;
        }

        int Empty(){
            return top == -1;
        }

        int IsFull(){
            return top == maxSize;
        }

        ElemType Top(){
            return element[top];
        }

        int Push(ElemType x){
            if(IsFull())
                return 0;
            element[++top] = x;
            return 1;
        }

        int Pop(){
            if(Empty())
                return 0;
            top--;
            return 1;
        }

        void clear(){
            top = -1;
        }

        void Destroy(){
            maxSize = -1;
            free(element);
            top = -1;
        }

};

int main(){
    stack a(10000);
    char s[maxn];
    char temp;
    cout<<"Please input the expression : "<<endl;
    cin>>s;
    int flag = 1;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            a.Push(s[i]);
        }
        if(s[i] == ')'){
            if(!a.Empty() && a.Top() == '('){
                a.Pop();
            }
            else {
                flag = 0;
            }
        }
        else if(s[i] == ']'){
            if(!a.Empty() && a.Top() == '['){
                a.Pop();
            }
            else {
                flag = 0;
            }
        }
        else if(s[i] == '}'){
            if(!a.Empty() && a.Top() == '{'){
                a.Pop();
            }
            else {
                flag = 0;
            }
        }
    }
    if(!a.Empty() && (a.Top() == '(' || a.Top() == '[' || a.Top() == '{')){
        flag = 0;
    }
    a.Destroy();
    if(flag){
        cout<<"Success! "<<endl;
    }
    else{
        cout<<"Fail!"<<endl;
    }
    return 0;
}