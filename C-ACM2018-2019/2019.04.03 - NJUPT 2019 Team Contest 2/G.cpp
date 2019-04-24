#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000+10;
long long n, k, num[maxn], res[maxn];
priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > que;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+n);
    int ind = 0;
    que.push(make_pair(num[0], 0));
    int ans = 0;
    while(!que.empty() && k){
        pair<int, int> tem = que.top();
        ans = tem.first;
        //cout<<ans<<endl;
        int pos = tem.second;
        que.pop();
        k--;
        if(pos < n - 1){
            que.push(make_pair(ans + num[pos + 1], pos + 1));
            que.push(make_pair(ans - num[pos] + num[pos + 1], pos + 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}
