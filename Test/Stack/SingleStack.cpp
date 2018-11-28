#include<cstring>
#include<iostream>
#include<algorithm>
#define ElemType char

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;

class stack{
    private:
        struct node {
            ElemType element;
            struct node *link;
        } *head, *top;
    public:
        stack(){
            head = (node *)malloc(sizeof(node));
            top = (node *)malloc(sizeof(node));
            head->element = -1;
            head->link= NULL;
            top->element = -1;
            top->link = head;
        }
        
        int Empty(){
            return top->link == head;
        }

        ElemType Top(){
            return top->link->element;
        }

        void Push(ElemType x){
            struct node* temp = (node *)malloc(sizeof(node));
            temp->element = x;
            temp->link = top->link;
            top->link = temp;
        }

        int Pop(){
            if(Empty())
                return 0;
            struct node* temp = top->link;
            top->link = top->link->link;
            free(temp);
            return 1;
        }

        void Destroy(){
            while(!Empty()){
                Pop();
            }
            free(top);
            free(head);
        }
};

int main(){
    stack a;
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