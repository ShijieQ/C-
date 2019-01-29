#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+10;
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
} 

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        for(int i = 1; i <= n; i++){
            cin>>p[i].first>>p[i].second;
        }
        
    }
}