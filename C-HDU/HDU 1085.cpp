#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1005;
bool F[1*maxn+2*maxn+5*maxn];
void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void sol(int a, int b, int c){
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                F[i+j*2+k*5] = 1;
            }
        }
    }
    for(int i = 1; i <= 1*maxn+2*maxn+5*maxn; i++){
        if(!F[i]){
            cout<<i<<endl;
            break;
        }
    }
}

int main(){
    init();
    int a, b, c;
    while(cin>>a>>b>>c){
        if(!a && !b && !c){
            break;
        }
        sol(a, b, c);
    }
}