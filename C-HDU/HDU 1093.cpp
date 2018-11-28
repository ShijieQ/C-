#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000000;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        long long int ans = 0;
        long long int t;
        cin>>t;
        for(long long int i = 1; i <= t; i++){
            long long int k;
            cin>>k;
            ans += k;
        }
        cout<<ans<<endl;
    }
}