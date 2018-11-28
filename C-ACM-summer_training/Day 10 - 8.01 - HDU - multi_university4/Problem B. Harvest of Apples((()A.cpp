#include <bits/stdc++.h>
#define fi first
#define se second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pb push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define FIN freopen("in.txt","r",stdin)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
using namespace std;
const int MX=1e5+7;
const int mod=1e9+7;

struct Query{
    int n,m,id;
}que[MX];
int pos[MX];
ll inv[MX],f[MX],ans[MX];
bool cmp(Query A,Query B){
    if(pos[A.n]!=pos[B.n]) return A.n<B.n;
    return A.m<B.m;
}

ll qpow(ll a,ll b){ll res=1;while(b){if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
void init(){
    f[1]=1;
    for(int i=2;i<MX;i++) f[i]=(f[i-1]*i)%mod;
    for(int i=1;i<MX;i++) inv[i]=qpow(f[i],mod-2);
}

ll C(int n,int m){
    if(n < 0 || m < 0 || m > n) return 0;
    if(m == 0 || m == n) return 1;
    return f[n]*inv[n-m]%mod*inv[m]%mod;
}
ll res=1;

int main(){
    init();
    int T;scanf("%d",&T);
    int block=(int)sqrt(MX);
    rep(i,1,MX-1) pos[i]=(i-1)/block;
    rep(i,1,T){
        scanf("%d%d",&que[i].n,&que[i].m);
        que[i].id=i;
    }
    sort(que+1,que+T+1,cmp);
    int N=1,M=0;
    rep(i,1,T){
        while(N<que[i].n){
            res=(2*res-C(N++,M)+mod)%mod;
        }
        while(N>que[i].n){
            res=((res+C(--N,M))*inv[2])%mod;
        }
        while(M<que[i].m){
            res=(res+C(N,++M))%mod;
        }
        while(M>que[i].m){
            res=(res-C(N,M--)+mod)%mod;
        }
        ans[que[i].id]=res;
    }
    rep(i,1,T)
        printf("%lld\n", ans[i]);
    return 0;
}
