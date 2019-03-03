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
const int maxn = 5000+10;
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first == b.first ? a.second < b.second:a.first < b.first;
}

int main(){
    int n, s, a, b;
    cin>>n>>s>>a>>b;
    long long int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin>>p[i].second>>p[i].first;
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n && s >= 0; i++){
        if(a + b >= p[i].second && s >= p[i].first){
            cnt++;
            s -= p[i].first;
        }
    }
    cout<<cnt<<endl;
    return 0;
}