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
const int maxn = 1e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
    int n;
    cin>>n;
    long long int mid = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    if(n & 1){
        mid = a[(1+n)/2];
    }
    else{
        mid = (a[(1+n)/2+1] + a[(1+n)/2])/2;
    }
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(a[i] - mid);
    }
    cout<<ans<<endl;
    return 0;
}