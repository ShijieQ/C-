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
char b[1000010];  
int main()   
{     
    scanf("%s",b);    
        c = 0;  
        a = 2;  
        ll phic=phi(mod);  
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
            ans=mod_pow(a,res,mod)%mod;
        }
        else
        {
            res=0;
            for(int i=0;i<len;i++)
            {
                res=res*10+b[i]-'0';
                res%=phic;
            }
            ans=mod_pow(a,res+phic,mod)%mod;
        }
        cout<<ans<<endl;
    //cout<<mod_pow(2,3,mod);
    return 0;  
}