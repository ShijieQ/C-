#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define ll long long
#define qwq(x) for(edge *o=head[x];o;o=o->next)
const int mod=1e6+7;
const int nmax=7e6+5;
struct edge{
    int to,dis;
    edge *next;
};
edge es[mod],*pt=es,*head[nmax];
int mo[nmax+1],pe[nmax];
bool vis[nmax+1];

void add(int u,int v,int d){
    pt->to = v;
    pt->dis = d;
    pt->next = head[u];
    head[u] = pt++;
}

int get(ll n){
    if(n <= nmax) 
        return mo[n];
    int tp = n%mod;
    for(edge *o = head[tp]; o; o = o->next) 
        if(o->to == n) 
            return o->dis;
    ll last,ans=0;
    for(ll i = 2; i <= n; i = last+1){
        last = n/(n/i);
        ans += (last-i+1)*get(n/i);
    }
    add(tp, n, 1-ans);
    return 1-ans;
}

int main(){
    mo[1] = 1;
    int cnt = 0,tp;
    for(int i = 2; i <= nmax; i++){
        if(!vis[i]) 
            pe[++cnt]=i,mo[i]=-1;
        for(int j = 1; i <= cnt; j++){
            tp = pe[j];
            if(tp*i > nmax) 
                break;
            vis[i*tp] = 1;
            if(i%tp == 0){
                mo[i*tp] = 0;
                break;
            } 
            mo[i*tp] =- mo[i];
        }
    }
    for(int i = 1;i <= nmax; i++)
        mo[i] += mo[i-1];
    ll n,m;
    scanf("%lld%lld",&n,&m);
    printf("%d\n",get(m)-get(n-1));
    system("pause");
    return 0;
}