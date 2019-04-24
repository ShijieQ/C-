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
// #define Online

using namespace std;
const int maxn = 5e6+100;
bool F[maxn];
int num = 0;
int ans[maxn];

void init(){
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            for(int k = 1; k*i < maxn; k++){
                int tem = i*k;
                while(tem % i == 0){
                    ans[i*k]++;
                    tem /= i;
                }
                F[i*k] = 1;
            }
        }
    }
    for(int i = 2; i < maxn; i++){
        ans[i] += ans[i-1];
    }
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        int l, r;
        scanf("%d%d", &r, &l);
        cout<<ans[r] - ans[l]<<endl;
    }
    return 0;
}