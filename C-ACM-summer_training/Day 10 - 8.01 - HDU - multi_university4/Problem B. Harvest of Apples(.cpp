#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 100005
#define mod 1000000007
#define LL long long
using namespace std;
//typedef long long LL;
//const LL maxn(1000005), mod(1e9 + 7);
LL Jc[maxn];
void calJc()    //求maxn以内的数的阶乘
{
    Jc[0] = Jc[1] = 1;
    for(LL i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}
/*
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

*/
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

LL C(LL a, LL b)    //计算C(a, b)
{
    return Jc[a] * niYuan(Jc[b], mod) % mod * niYuan(Jc[a - b], mod) % mod;
}

int main(){
	LL n, m;
	cin>>n>>m;
	cout<<C(n, m)<<endl;
}
