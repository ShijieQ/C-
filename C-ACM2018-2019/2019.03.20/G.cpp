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
const int MAX = 5e4+10;
pair<int, int> p[maxn];
int A[maxn];

int main(){
    int n, k;
    cin>>n>>k;
    int flag = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin>>p[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin>>p[i].second;
        if(!p[i].second){
            A[i] = p[i].first + A[i-1];
        }
        else{
            A[i] = A[i-1];
            ans += p[i].first;
        }
    }
    int maxx = -INF;
    for(int i = 0; i+k <= n; i++){
        if(maxx < (A[i+k] - A[i])){
            maxx = A[i+k] - A[i];
        }
    }
    cout<<ans+maxx<<endl;
    return 0;
}