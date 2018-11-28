/*当你要计算 A^B%C的时候 
因为此题中的B很大，达到10^100000，所以我们应该联想到降幂公式。  
 
降幂公式：A^B%C = A^(B%phi(C) + phi(C))%C 
分两种情况：  
当B<=phi(C)时，直接用快速幂计算A^B mod C 
当B>phi(C)时，用快速幂计算A^(B mod phi(C)+phi(C)) mod C  
*/  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
#include <string>  
#include <cstdlib>  
using namespace std;  
const int mod = 1e9+7;  
typedef long long ll;  
ll phi(ll n)   //求欧拉函数值   
{  
    int ans=n,temp=n;  
    for(int i=2;i*i<=temp;i++)   
    {  
        if(temp%i==0)   
        {  
            ans-=ans/i;  
            while(temp%i== 0) temp/=i;  
        }  
    }  
    if(temp>1) ans-=ans/temp;  
    return ans;  
}  
ll mod_pow(ll x,ll n,ll mod)  //快速幂   
{     
    ll ans=1;  
    while(n)   
    {  
        if(n%2==1) ans=ans*x%mod;  
        x=x*x%mod;  
        n/=2;  
    }  
    return ans;  
}  
ll a,c;  
char b[100010];  
int main()   
{     
    int T;
    scanf("%d", &T);
    while(T--)   
    {  
        scanf("%s",b);  
        a = 2;  
        ll phic=phi(mod);  
        // cout<<phic<<endl;
        int i,len=strlen(b);  
        ll res=0,ans;   
        for( i=0;i<len;i++)
        {
            res=res*10+b[i]-'0';
            if(res>phic)
            break;
        }
        if(i==len)
        {
            ans=mod_pow(a,res-1,mod)%mod;
        }
        else
        {
            res=0;
            for(int i=0;i<len;i++)
            {
                res=res*10+b[i]-'0';
                res%=phic;
            }
            cout<<res<<endl;
            res--;
            ans=mod_pow(a,res+phic,mod)%mod;
        }
        cout<<ans<<endl;
    }  
    //cout<<mod_pow(2,3,mod);
    return 0;  
}