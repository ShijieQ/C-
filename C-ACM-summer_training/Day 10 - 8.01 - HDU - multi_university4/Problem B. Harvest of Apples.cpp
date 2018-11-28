#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
/*
int quick_power_mod(int a,int b,int m){
    int result = 1;
    int base = a;
    while(b>0){
         if(b & 1==1){
            result = (result*base) % m;
         }
         base = (base*base) %m;
         b >>=1;
    }
    return result;
}

ll comp(ll a, ll b, int p) {//composite num C(a,b)%p
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;
    int ans = 1, ca = 1, cb = 1;
    for(ll i = 0; i < b; ++i){
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*quick_power_mod(cb, p - 2, p)) % p;
    return ans;
}

ll lucas(ll n, ll m, ll p) {
     ll ans = 1;
     while(n&&m&&ans) {
        ans = (ans*comp(n%p, m%p, p)) % p;//also can be recusive
        n /= p;
        m /= p;
     }
     return ans;
}*/

typedef long long LL;
const LL maxn(1000005), mod(1e9 + 7);
LL Jc[maxn];
LL Lucas(LL a, LL b);
void calJc()    //求maxn以内的数的阶乘
{
    Jc[0] = Jc[1] = 1;
    for(LL i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}
/*
//拓展欧几里得算法求逆元
void exgcd(LL a, LL b, LL &x, LL &y)    //拓展欧几里得算法
{
    if(!b) x = 1, y = 0;
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

LL niYuan(LL a, LL b)   //求a对b取模的逆元
{
    LL x, y;
    exgcd(a, b, x, y);
    return (x + b) % b;
}
*/

//费马小定理求逆元
LL pow(LL a, LL n, LL p)    //快速幂 a^n % p
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

LL niYuan(LL a, LL b)   //费马小定理求逆元
{
    return pow(a, b - 2, b);
}

LL C(LL a, LL b)    //计算C(a, b)
{
    return Jc[a] * niYuan(Jc[b], mod) % mod
        * niYuan(Jc[a - b], mod) % mod;
}

LL Lucas(LL a, LL b)
{
    if(a < mod && b < mod)
        return C(a, b);
    return
        C(a % mod, b % mod) * Lucas(a / mod, b / mod);
}

int main(){
	int T;
	cin>>T;
	while(T--){
		long long int n, m;
		scanf("%lld%lld", &n, &m);
		n--;
		long long int ans = 0;
		/*
		ans += lucas(n, 0, maxn);
		cout<<ans<<endl;
		ans += lucas(n, m, maxn);
		cout<<ans<<endl;
		for(int i = 1; i < m; i++){
    		if(i > n/2)
    			ans += 2*lucas(n, n-m, maxn);
    		else
    			ans += 2*lucas(n, m, maxn);
    		ans %= maxn;
    	}
    	*/
    	ans += Lucas(n, 0);
		cout<<ans<<endl;
		ans += Lucas(n, m);
		cout<<ans<<endl;
		for(int i = 1; i < m; i++){
    		if(i > n/2)
    			ans += 2*Lucas(n, n-m);
    		else
    			ans += 2*Lucas(n, m);
    		ans %= maxn;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}
