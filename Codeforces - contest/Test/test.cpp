#include<bits/stdc++.h>

///#include<ext/pb_ds/assoc_container.hpp>
///#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((ll)(2e9))
#define pi (2*acos(0))
#define mp make_pair
#define M (998244353)
#define xx first
#define yy second
#define NN ((ll)(1e6+2))
#define N ((ll)(2e5+5))
#define eps 0
#define log 20
#define pb push_back
#define MOD 998244353


using namespace std;
///using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long lu;

///typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;

int x[N], t[N], cnt[N];

int main()
{
    int n, m, i, fst, scn, j;
    scanf("%d %d",&n,&m);
    for(i = 0; i<n+m; i++) scanf("%d",&x[i]);
    for(i = 0; i<n+m; i++) scanf("%d",&t[i]);
    for(i = 0; i<n+m; i++) if(t[i]){
        scn = fst = i;
        break;
    }
    for(i = 0; i<n+m; i++){
        if(i>scn){
            fst = scn;
            scn = n+m;
            for(j = i; j<n+m; j++){
                if(t[j]){
                    scn = j;
                    break;
                }
            }
        }
        if(t[i]) continue;
        if(scn==n+m || abs(fst-i)<=abs(i-scn)) cnt[fst]++;
        else cnt[scn]++;
    }

    for(i = 0; i<n+m; i++){
        if(t[i]) printf("%d ",cnt[i]);
    }
    return 0;
}