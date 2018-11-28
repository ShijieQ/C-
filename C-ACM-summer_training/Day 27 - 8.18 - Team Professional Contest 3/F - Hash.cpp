#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+100;
int e[maxn][maxn], ans[maxn][maxn], hx[maxn], hy[maxn], r[maxn], z[maxn];

template <class T>
inline bool scan_d(T &ret) 
{
    char c;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c<'0' || c>'9') c=getchar();
    ret = c-'0';
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    return 1;
}

int main()
{
    int n, flag;
    while(scan_d(n) && n){
        memset(hx, 0, sizeof(hx));
        memset(hy, 0, sizeof(hy));
        memset(z, 0, sizeof(z));
        flag = 1;
        int x;
        for(int i = 1; i <= n; i++) 
            r[i] = rand()%1000000;
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
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                hx[i] += e[j][i]*r[j];
                hy[i] += ans[j][i]*r[j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                z[j] += hx[i]*e[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            if(z[i] != hy[i])    
                flag = 0;
        }
        if(flag)    
            puts("YES");
        else        
            puts("NO");
    }
    return 0;
}