#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+100;
int res[maxn][maxn];
int e[maxn][maxn], ans[maxn][maxn];

template <class T>
inline bool scan_d(T &ret) {
    char c;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c<'0' || c>'9') c=getchar();
    ret = c-'0';
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    return 1;
}

int main(){
    int n, flag;
    while(scan_d(n) && n){
        memset(res, 0, sizeof(res));
        memset(e, 0, sizeof(e));
        memset(ans, 0, sizeof(ans));
        flag = 1;
        int x;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scan_d(x);
                e[i][j] = x;
            }
        } 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scan_d(x);
                ans[i][j] = x;
                if(flag){
                    for(int k = 1; k <= n; k++){
                        res[i][j] += e[i][k]*e[k][j];
                    }
                }else{
                    continue;
                }
                if(res[i][j] != ans[i][j])
                    flag = 0;
            }
        }
        if(flag)    
            puts("YES");
        else        
            puts("NO");
    }
    return 0;
}