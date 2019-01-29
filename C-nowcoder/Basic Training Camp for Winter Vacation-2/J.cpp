#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+50;
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first:a.second < b.second;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin>>p[i].second;
    }
    sort(p+1, p+n+1, cmp);
    int tim = 0;
    p[0].second = -2;
    bool flag = 1;
    for(int i = 1; i <= n && flag; i++){
        tim += (p[i].second - p[i-1].second - 2);
        if(tim < p[i].first){
            flag = 0;
            break;
        }
        else {
            tim -= p[i].first;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}