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
const int maxn = 1e3+10;
long long int cnt = 0;
int ans[maxn];

void solve(){
    for(int i = 1; i < maxn; i++){
        ans[i] = 1;
    }
    ans[1] = ans[0] = 1;
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j <= i/2; j++){
            ans[i] += ans[j];
        }
    }
}

void solve2(){
    ans[0] = ans[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(i & 1){
            ans[i] = ans[i-1];
        }
        else{
            ans[i] = ans[i-1] + ans[i/2];
        }
    }
}

int main(){
    solve2();
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
    return 0;
}