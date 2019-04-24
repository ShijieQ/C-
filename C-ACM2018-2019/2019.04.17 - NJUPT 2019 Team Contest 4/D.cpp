#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e4+10;

int main(){
    int T;
    cin>>T;
    long long int ans = 0;
    while(T--){
        int k;
        scanf("%d", &k);
        if(k > 1)   ans++;
    }
    cout<<ans<<endl;
    return 0;
}