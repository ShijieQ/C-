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
const int maxn = 20+5;
pair<pair<int, int>, int> p[maxn*maxn];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second > b.second;
}

void check(int m, int n){
    for(int i = 1; i <= n*m; i++){
        cout<<"("<<p[i].first.first<<", "<<p[i].first.second<<")   "<<p[i].second<<endl;
    }
}

int main(){
    int m, n, k;
    cin>>m>>n>>k;
    int cnt = 0;
    long long int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>p[++cnt].second;
            p[cnt].first.first = i;
            p[cnt].first.second = j;
        }
    }
    sort(p + 1, p + 1 + m*n, cmp);
    //check(m, n);
    int pos_x = 0, pos_y = p[1].first.second;
    for(int i = 1; i <= m*n; i++){
        // cout<<pos_x<<", "<<pos_y<<"   time = "<<k<<endl;
        // cout<<abs(pos_x - p[i].first.first) + abs(pos_y - p[i].first.second) + p[i].first.second + 1<<endl;
        if(k > abs(pos_x - p[i].first.first) + abs(pos_y - p[i].first.second) + p[i].first.second + 1){
            k -= (abs(pos_x - p[i].first.first) + abs(pos_y - p[i].first.second) + 1);
            pos_x = p[i].first.first;
            pos_y = p[i].first.second;
            //cout<<"** "<<pos_x - p[i].first.first<<"  "<<pos_y - p[i].first.second<<endl;
            ans += p[i].second;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}