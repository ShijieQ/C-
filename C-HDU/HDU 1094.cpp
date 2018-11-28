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
    while(cin>>T){
        long long int ans = 0;
        for(long long int i = 1; i <= T; i++){
            long long int k;
            cin>>k;
            ans += k;
        }
        cout<<ans<<endl;
    }
}