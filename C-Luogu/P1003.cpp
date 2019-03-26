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
const int maxn = 1e5+10;
pair<pair<int, int>, pair<int, int> > q[maxn];

int main(){
    int n, ans = -1;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x, y, x_len, y_len;
        cin>>x>>y>>x_len>>y_len;
        q[i].first.first = x;
        q[i].first.second = y;
        q[i].second.first = x_len;
        q[i].second.second = y_len;
    }
    int x, y;
    cin>>x>>y;
    for(int i = 1; i <= n; i++){
        if(x >= q[i].first.first && x <= q[i].first.first + q[i].second.first && y >= q[i].first.second && y <= q[i].first.second + q[i].second.second){
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
