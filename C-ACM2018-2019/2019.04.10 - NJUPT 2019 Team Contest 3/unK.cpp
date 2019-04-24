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
//#define Online

using namespace std;
const int maxn = 1e4+10;
const int MAX = 5e3+10;
string q;
char ans[maxn][MAX];
int k, n;

void check(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    scanf("%d%d", &k, &n);
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ans[i][j] = '0';
        }
    }
    for(int i = 1; i <= n; i++){
        getline(cin, q);
        for(int j = 0; j < 3; j++){
            ans[i][q[4*j] - '0'] = q[4*j + 2];
        }
    }
    check();
    return 0;
}