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
const int maxn = 2e5+10;
int k, a;
char x;

void solve(){
    char ch;
    int num = 0;
    int signflag = 1, equalflag = 1;
    while((ch = getchar()) != EOF){
        if(ch >= '0' && ch <= '9'){
            num = num*10 + ch - '0';
        }
        else{
            if(ch >= 'a' && ch <= 'z'){
                x = ch;
                a += (num ? num*signflag*equalflag : signflag*equalflag);
            }
            else{
                k += num*signflag*equalflag;
            }
            num = 0;
        }
        if(ch == '-'){ 
            signflag = -1;
        }
        if(ch == '+'){
            signflag = 1;
        }
        if(ch == '='){ 
            equalflag = -1;
            signflag = 1;
        }
    }
    if(num != 0){
        k += num*signflag*equalflag;
    }
}

int main(){
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    solve();
    // cout<<"a = "<<a<<endl;
    // cout<<"k = "<<k<<endl;
    printf("%c=%.3f\n", x, k ? -1.0*k/a : 0);
    return 0;
}