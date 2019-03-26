#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 25*2500+100;
char a[maxn];
int len = 0;

void read(){
    char ch;
    while((ch = getchar()) != 'E'){
        if(ch == 'W' || ch == 'L'){
            a[len++] = ch;
        }
        else {
            continue;
        }
    }
}

void solve(){
    if(!len){
        cout<<"0:0\n\n0:0\n";
        return ;
    }
    int A = 0, B = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == 'W'){
            A++;
        }
        else{
            B++;
        }
        if((A >= 11 || B >= 11) && (abs(A - B) >= 2)){
            cout<<A<<":"<<B<<endl;
            A = 0; B = 0;
        }
    }
    cout<<A<<":"<<B<<endl<<endl;
    A = 0; B = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == 'W'){
            A++;
        }
        else{
            B++;
        }
        if((A >= 21 || B >= 21) && (abs(A - B) >= 2)){
            cout<<A<<":"<<B<<endl;
            A = 0; B = 0;
        }
    }
    cout<<A<<":"<<B<<endl;
}

int main(){
    read();
    solve();
    return 0;
}
