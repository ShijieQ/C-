#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
unsigned long long  n, a, b, c,d,ans;
unsigned long long  list2[40000100];

void init() {
    list2[0] = 1;
    for (int i = 1; i <=40000100; i++) {
        list2[i] = list2[i-1] * 2;
        list2[i] %= mod;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin>>T;
    while(T--){
        long long int a, b, c, d, ans = 0;
        cin>>a>>b>>c>>d;
        ans = list2[a + b];
        ans += (b + d + 1)*list2[a + c];
        ans -= (b + 1)*list2[a];
        ans %= 998244353;
        if (ans < 0) 
            ans += 998244353;
        cout << ans << endl;
    }
    return 0;
}