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
    int k = rand();
    srand(k);
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
            }
        }
        if(n >= 100){
        for(int i = 1; i <= 100; i++){
            if(!flag)    
                break;
            for(int j = 1; j <= 100; j++){
                int X = rand()%n+1;
                int T = 1000;
                while(T--){
                    ;
                }
                int Y = rand()%n+1;
                res[X][Y] = 0;
                for(int k = 1; k <= n; k++){
                    res[X][Y] += e[X][k]*e[k][Y];
                }
                if(res[X][Y] != ans[X][Y])
                    flag = 0;
            }
        }
        }else{
        for(int i = 1; i <= n; i++)
        {
            if(!flag)    break;
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    res[i][j] += e[i][k]*e[k][j];
                }
                if(res[i][j] != ans[i][j])
                    flag = 0;
            }
        }
        }
        if(flag)    
            puts("YES");
        else        
            puts("NO");
    }
    return 0;
}
/*
3
2 0 1
1 0 3
1 1 0
5 1 2
5 3 1
3 0 4
3
2 0 1
1 0 3
1 1 0
5 1 2
5 3 2
3 0 4
0
*/