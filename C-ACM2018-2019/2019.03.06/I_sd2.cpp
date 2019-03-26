#include <cstdio>
using namespace std;
typedef long long ll;
ll a,b,ans=1;
ll ksm(ll x,ll y){//快速幂
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%9901;
        x=x*x%9901; y>>=1;
    }
    return ans;
}
ll answer(ll x,ll y){
    if ((x-1)%9901==0) return (y+1)%9901;//特判
    int a=ksm(x,y+1); a=(a+9900)%9901;//分子在0到9900之间
    int b=ksm(x-1,9899); return a*b%9901;//乘法逆元
}
int main(){
    scanf("%lld%lld",&a,&b);
    for (ll i=2;i*i<=a;i++)
    if (a%i==0){//质因数分解
        ll sum=0;
        while (a%i==0) sum++,a/=i;
        ans=ans*answer(i,sum*b)%9901;
    }
    if (a>1) ans=ans*answer(a,b)%9901;//特判
    printf("%lld",ans);
    return 0;
}