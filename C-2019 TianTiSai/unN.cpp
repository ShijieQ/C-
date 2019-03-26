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
const int maxn = 1e4+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
pair<int, pair<int, int> > p[maxn];

// bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
//     return a.second.first == b.second.second ? a.second.second < 
// }

int main(){
    int N;
    cin>>N;
    int l = -INF, r = INF, x1 = INF, y1 = -INF;
    for(int i = 1; i <= N; i++){
        cin>>p[i].first>>p[i].second.first>>p[i].second.second;
        l = max(l, p[i].second.first);
        r = min(r, p[i].second.second);
        x1 = min(x1, p[i].first);
        y1 = max(y1, p[i].first);
    }
    cout<<x1<<" "<<l<<" "<<y1<<" "<<r;
    return 0;
}