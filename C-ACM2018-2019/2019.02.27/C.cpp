#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
pair<int, int> p[maxn];

int main(){
    int n, x;
    cin>>n>>x;
    long long int ans = 0;
    p[0].second = 0;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin>>l>>r;
        p[i].first = l;
        p[i].second = r;
        ans += (r - l + 1) + (p[i].first - p[i-1].second - 1 >= 0 ? (p[i].first - p[i-1].second - 1)%x:0);
    }
    cout<<ans<<endl;
    return 0;
}