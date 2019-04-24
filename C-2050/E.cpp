#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e4+100;
int sch[maxn];
int a[maxn];
int rel[maxn];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(sch, 0, sizeof(sch));
        memset(a, 0, sizeof(a));
        memset(rel, 0, sizeof(rel));
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sch[a[i]]++;
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
            rel[i] = sch[i]/k;
        }
        for(int i = 1; i <= n/2; i++){
            if(rel[a[i]] > 0){
                rel[a[i]]--;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}