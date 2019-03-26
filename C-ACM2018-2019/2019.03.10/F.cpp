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
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 5e4+100;
int rocks[maxn];

int main(){
    int L, N, M;
    scanf("%d%d%d", &L, &N, &M);
    int shortlen = INF;
    for(int i = 1; i <= N; i++)
        scanf("%d", &rocks[i]);
    sort(rocks + 1, rocks + 1 + N);
    rocks[0] = 0; rocks[N+1] = L;
    // for(int i = 1; i <= N; i++)
    //     shortlen = min(shortlen, rocks[i] - rocks[i-1]);
    int l = 0, r = L;
    while(l <= r){
        int mid = (l + r) >> 1;
        int temp = 0, cnt = 0;
        for(int i = 1; i <= N+1; i++)
            if(mid >= rocks[i] - rocks[temp])
                cnt++;
            else
                temp = i;
        if(cnt > M)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout<<l<<endl;
    return 0;
}