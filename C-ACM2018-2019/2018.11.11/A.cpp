#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e5+10;
stack<int> s;
int a[maxn];
//string s;

int main(){
    int n;
    cin>>n;
    char order[10];
    int should = 1;
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++){
        scanf("%s", order);
        if(order[0] == 'a'){
            int tem;
            scanf("%d", &tem);
            s.push(tem);
        }
        else{
            if(s.empty()){
                should++;
                continue;
            }
            if(s.top() == should){
                s.pop();
            }
            else{
                while(!s.empty()){
                    s.pop();
                }
                cnt++;
            }       
            should++;     
        }
    }
    cout<<cnt<<endl;
    return 0;
}