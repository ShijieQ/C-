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
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>p[i].first;
    }
    for(int i = 1; i <= m; i++){
        cin>>p[i].second;
    }
    sort(p+1, p+1+m, cmp);
    long long int ans = 0;
    for(int i = 1; n && i <= m; i++){
        if(p[i].first > n){
            ans += n*p[i].second;
            n = 0;
        }
        else {
            ans += p[i].second*p[i].first;
            n -= p[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}