#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 0x7ffffff;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long sol(int a){
    long long int ans = 0;
    for(int i = 1; i <= sqrt(a); i++){
        ans += a/i;
    }
    for(int i = 1; i <= sqrt(a); i++){
        int k = a/i - a/(i+1);
//        cout<<k<<endl;
        ans += 1LL * i * k;
    }
    int tem = int (sqrt(a));
    if(tem == a / tem) 
        ans -= tem;
    return ans;
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        int n;
        cin>>n;
        long long int ans = sol(n);
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}