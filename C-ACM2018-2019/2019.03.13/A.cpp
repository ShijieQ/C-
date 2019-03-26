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
const int maxn = 3e5+100;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
deque<int> q;
long long int a[maxn];
long long int sum[maxn];
long long int ans = -INF;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    q.push_front(0);
    for(int i = 1; i <= n; i++){
        while(!q.empty() && sum[q.front()] > sum[i])
            q.pop_front();
        q.push_front(i);
        while(!q.empty() && i - q.back() > m)
            q.pop_back();
        ans = max(ans, sum[i] - sum[q.back()]);
    }
    cout<<ans<<endl;
    return 0;

}