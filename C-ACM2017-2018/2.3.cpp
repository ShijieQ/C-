#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
long long max_mana[1010][10010],c[1010],cost[1010];
long long n,w,B,X;
int main()
{
    int n;
    while(scanf("%I64d %I64d %I64d %I64d",&n,&w,&B,&X) != EOF){
        for(long long i = 0; i < n; i++)
            scanf("%I64d",&c[i]);
        for(long long i = 0; i < n; i++)
            scanf("%I64d",&cost[i]);
        memset(max_mana,0,sizeof(max_mana));
        max_mana[0][0] = w;
        long long num = 0;
        for(int i = 0; i < n; i++){//ËùÔÚµÄÊ÷
            for(long long j = 0; j <= num; j++){
                for(long long k = 0; k < c[i]; k++){
                    long long mid = max_mana[i][j];
                    mid = mid - k * cost[i];
                    if(mid < 0) break;
                    mid = mid + X;
                    if(mid > w+(j+k)*B) mid = w+(j+k)*B;
                    if(max_mana[i+1][j+k] < mid) max_mana[i+1][j+k] = mid;
                }
            num = num + c[i];
            }
        }
        for(int i = 10000; i > 0; i--){
            if(max_mana[n+1][i] > 0){
                printf("%d\n");
                break;
            }
        }
    }
}
