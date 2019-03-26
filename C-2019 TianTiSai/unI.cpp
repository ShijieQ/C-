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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
map<int, pair<int, int> > mp;
int vis[maxn];

int main(){
    int fri, n;
    cin>>fir>>n;
    for(int i = 1; i <= n; i++){
        int d, val, nex;
        cin>>d>>val>>nex;
        mp[d].second.first = val;
        mp[d].second.second = nex;
        
    }
    return 0;
}