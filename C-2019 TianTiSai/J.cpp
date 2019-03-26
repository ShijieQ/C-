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
const int maxn = 1e4+100;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second*b.first == b.second*a.first ? a.first > b.first:a.second*b.first > b.second*a.first;
}

int main(){
    int n, k;
    double ans = 0;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>p[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin>>p[i].second; 
    }
    sort(p + 1, p + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        if(k >= p[i].first){
            k -= p[i].first;
            ans += p[i].second;
        }
        else{
            ans += 1.0*k*p[i].second/p[i].first;    
            k = 0;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}