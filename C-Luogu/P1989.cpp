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
int n, x;

void solve(){
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp){
            ans += (temp%10 == x ? 1:0);
            temp /= 10;
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin>>n>>x;
    solve();    
    return 0;
}