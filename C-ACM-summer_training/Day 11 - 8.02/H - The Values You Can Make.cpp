#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int a[N],n,p;
int dp[505][505],tmp[505];
vector<int>ret;
int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;++i){
      scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
      for(int j=p;j>=a[i];--j){
        for(int k=0;k+a[i]<=p;++k)
        if(dp[j-a[i]][k])dp[j][k]=dp[j][k+a[i]]=1; 
      }
    }
    for(int i=0;i<=p;++i)
      if(dp[p][i])ret.push_back(i);
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size()-1;++i)
      printf("%d ",ret[i]);
    printf("%d\n",ret[ret.size()-1]);
    return 0;
}
