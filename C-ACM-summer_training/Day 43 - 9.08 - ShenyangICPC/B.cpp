#include<iostream>
#include <stack>
#include<string.h>
#include<math.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    char s[300];
    while(scanf("%s",s)!=EOF){
        int w=strlen(s);
        for(int i=w;i>=1;i--){
            s[i]=s[i-1];
        }
        s[w+1]=')';
        s[0]='(';
        s[w+2]='\0';
        stack<pair<int,int> > num;
        stack<char> op;
        char flag1='\0',flag2='\0';
        for(int i=0;i<strlen(s);i++){
            int f=0;
            pair<int,int> d;
            d.second=d.first=0;
            if(isdigit(s[i])){
                d.first=s[i]-'0';
                f=1;
                while(isdigit(s[i+1])){
                    f=1;
                    d.first=d.first*10+s[i+1]-'0';
                    i++;
                }
                d.second=d.first;
                if((!isdigit(flag1))&&flag1!=')'&&flag2=='-'){
                    d.first=-d.first;
                    d.second=-d.second;
                    op.pop();
                }
            }
            flag1=flag2;
            flag2=s[i];
            if(f){
                pair<int,int> w;
                w.first=d.first;
                w.second=d.second;
                num.push(w);
            }
            if(s[i]=='+'||s[i]=='-'){
                while(!op.empty()&&(op.top()=='*'||op.top()=='d'||op.top()=='+'||op.top()=='-')){
                    if(op.top()=='+'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=a.first+b.first;
                        w.second=a.second+b.second;
                        num.push(w);
                    }
                    if(op.top()=='-'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=b.first-a.first;
                        w.second=b.second-a.second;
                        num.push(w);
                    }
                    if(op.top()=='d'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    if(op.top()=='*'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=a.first*b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    op.pop();
                }
                op.push(s[i]);
            }
            if(s[i]=='*'){
                while(!op.empty()&&(op.top()=='*'||op.top()=='d')){
                    if(op.top()=='d'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    if(op.top()=='*'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=a.first*b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    op.pop();
                }
                op.push(s[i]);
            }
            if(s[i]=='(')
                op.push(s[i]);
            if(s[i]=='d'){
                while(!op.empty()&&op.top()=='d'){
                    pair<int,int> a=num.top();
                    num.pop();
                    pair<int,int> b=num.top();
                    num.pop();
                    pair<int,int> w;
                    w.first=b.first;
                    w.second=a.second*b.second;
                    num.push(w);
                    op.pop();
                }
                op.push(s[i]);
            }
            if(s[i]==')'){
                while(op.top()!='('){
                    if(op.top()=='d'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    if(op.top()=='*'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=a.first*b.first;
                        w.second=a.second*b.second;
                        num.push(w);
                    }
                    if(op.top()=='+'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=a.first+b.first;
                        w.second=a.second+b.second;
                        num.push(w);
                    }
                    if(op.top()=='-'){
                        pair<int,int> a=num.top();
                        num.pop();
                        pair<int,int> b=num.top();
                        num.pop();
                        pair<int,int> w;
                        w.first=b.first-a.first;
                        w.second=b.second-a.second;
                        num.push(w);
                    }
                    op.pop();
                }
                op.pop();
            }
        }
        cout<<num.top().first<<" "<<num.top().second<<endl;
    }
}