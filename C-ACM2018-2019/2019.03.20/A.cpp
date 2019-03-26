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
int sum[maxn];

int main(){
    int n;
    cin>>n;
    sum[0] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        sum[i] = sum[i-1] + temp;
        //cout<<sum[i]<<endl;
    }
    for(int i = 1; i <= n-1; i++){
        int l = sum[i];
        int r = sum[n] - sum[i];
        if(l == r){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}