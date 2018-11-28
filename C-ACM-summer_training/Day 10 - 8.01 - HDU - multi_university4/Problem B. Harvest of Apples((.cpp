#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define LL long long
#define maxx 100005
using namespace std;
struct node{
	int id;
	LL anss; 
}a[maxx];

const int mod = 1000000007;
LL mub[100005];
LL x, y ;

void init(){//预处理阶乘
    mub[0] = 1;//注意0！ = 1
    for(int i=1; i<=100005; i++){
        mub[i] = mub[i-1] * i % mod;
    }
}

inline LL extend_gcd(LL a, LL b, LL &x, LL &y){//扩展欧几里得求逆元x
    if(a == 0 && b == 0)
        return -1;
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    LL d = extend_gcd(b, a % b, y, x);
        y -= a / b * x;
    return d;
}

inline LL mod_reverse(LL a, LL n){//规范逆元X
    LL d = extend_gcd(a, n, x, y);
    if(d == 1)
        return ( x % n + n ) % n;
    else
        return -1;
}

LL solve(LL a, LL b){
    if(a > b) return 0;
    LL nn = mod_reverse((mub[a] * mub[(b + mod - a) % mod]) % mod, mod);
    return mub[b] * nn % mod;
}

void to_solve(LL a, LL b){//Lucas降数据
    if(b < mod){
        solve(a, b);
        return;
    }
    cout << solve(a/mod, b/mod) * solve(a%mod, b%mod) << endl;
}

int main(){
//    freopen("comb.in","r",stdin);
//    freopen("comb.out","w",stdout);
	int T;
	cin>>T;
	init();
	/*
	for(int i = 1; i <= maxx; i++){
		for(int j = 0; j <= i; j++)
			a[i].id = j;
			a[i].z = solve(j,i);
	}*/
	
	while(T--){
    	LL a, b;
    	cin >> b >> a;
    	LL ans = 0;
    	for(int i = 0; i <= a; i++){
    		ans += solve(i,b);
//    		cout<<solve(i,b)<<endl;
    		ans %= mod;
    	}
    	cout<<ans<<endl;
    }
}
