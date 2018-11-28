#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
const int mod=1000000007;
const int MOD = 1000000007;
int fac[N], inv[N];
int powi(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % MOD)
        if (b & 1) c = 1ll * c * a % MOD;
    return c;
}
int C(int a, int b)
{
    return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}
int n,m;

struct node{
    int n,m,id;
}q[100005];
int cmp(node a,node b){
    return a.n<b.n;
}
int ans[100005];
vector<node>lst[N];
int in_chunk[100004];
int main(){
    int mx=100000;
    fac[0] = 1; 
    for (int i = 1; i <= mx; ++ i) 
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[mx] = powi(fac[mx], MOD - 2); 
    for (int i = mx - 1; ~i; -- i) 
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    int chunk=sqrt(mx);
    int cnt=1;
    for (int i = 1; i <= mx; i += chunk, ++ cnt){
        for (int j = i; j < i + chunk && j <= mx; ++ j)
            in_chunk[j] = cnt;
     //   cout<<cnt<<endl;
    }

    cnt--;
    int T;
    scanf("%d",&T);
    for (int i = 1; i <= T; ++ i)
    {
        scanf("%d%d", &q[i].n, &q[i].m), q[i].id = i;
        lst[in_chunk[q[i].m]].push_back(q[i]);
    }
    for(int i=1;i<=cnt;i++)
    if(lst[i].size())
    {
        sort(lst[i].begin(), lst[i].end(), cmp);
        int sum=0;
        int l=-1,r=lst[i][0].n;
        for(int j=0;j<lst[i].size();j++){
        while(r<lst[i][j].n)sum=(0ll+mod+sum+sum-C(r++,l))%mod;
        while(l<lst[i][j].m)sum=(sum+C(r,++l))%mod;
        while(l>lst[i][j].m)sum=(sum+mod-C(r,l--))%mod;
        ans[lst[i][j].id]=sum;
    }
    }
    for(int i=1;i<=T;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}