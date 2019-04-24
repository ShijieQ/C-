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
#define Online

using namespace std;
const int maxn = 2e5+10;
int a[maxn];
vector<pair<int, pair<int, int> > > ans;
map<int, int> mp;
int n;

void solve(int pos){
    for(int i = pos; i >= 2; i--){
        if(a[i] != a[i - 1]){
            if(a[i - 1] + abs(a[i - 1] - a[i]) == a[i]){
                ans.push_back({1, {i - 1, i}});
            }
            else if(a[i - 1] - abs(a[i - 1] - a[i]) == a[i]){
                ans.push_back({2, {i - 1, i}});
            }
        }
        a[i - 1] = a[i];
    }
    for(int i = pos; i <= n - 1; i++){
        if(a[i] != a[i + 1]){
            if(a[i + 1] + abs(a[i + 1] - a[i]) == a[i]){
                ans.push_back({1, {i + 1, i}});
            }
            else if(a[i + 1] - abs(a[i + 1] - a[i]) == a[i]){
                ans.push_back({2, {i + 1, i}});
            }
        }
        a[i + 1] = a[i];
    }
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int sum = 0;
    cin>>n;
    int num = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(++mp[a[i]] > cnt){
            cnt = mp[a[i]];
            num = a[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == num){
            solve(i);
            break;
        }
    }
    int siz = ans.size();
    cout<<siz<<endl;
    for(int i = 0; i < siz; i++){
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }
    return 0;
}