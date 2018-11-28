#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1010;
int num,n,k;
vector<int>G[maxn];
int d[maxn*maxn],g[maxn][maxn],vis[maxn];
struct node{
	int x,y;
}p[maxn];
bool dfs(int cnt,int m){
	if(cnt>n)
		return true;
	if(vis[cnt])
		return dfs(cnt+1,m);
	for(int i=0;i<(int)G[cnt].size();++i){
		m+=!vis[G[cnt][i]];
		vis[G[cnt][i]]++;
	}
	if(m<=k&&dfs(cnt+1,m))
		return true;
	int temp=m;
	for(int i=0;i<(int)G[cnt].size();++i){
		vis[G[cnt][i]]--;
		m-=!vis[G[cnt][i]];
	}
	if(G[cnt].size()!=1){
		vis[cnt]++;
		if(m+1<=k&&m+1<temp&&dfs(cnt+1,m+1))
			return true;
		vis[cnt]--;
	}
	return false;
}
bool judge(int dist){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(g[i][j]>dist){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	return dfs(1,0);
}
int binary_search(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(judge(d[mid]))
			r=mid;
		else l=mid+1;
	}
	return l;
} 
int main(){
	scanf("%d%d",&n,&k);
	num=0;
	d[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			d[++num]=g[i][j]=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);			
		}
	}
	sort(d,d+num+1);
	num=unique(d,d+num+1)-d-1;
	int mx=binary_search(0,num);
	judge(d[mx]);
	bool flag=false;
	for(int i=n;i>=1;--i){
		if(vis[i]){
			if(flag) putchar(' ');
			printf("%d",i);
			k--;
			flag=true;
		}
	}
	for(int i=n;i>=1&&k>0;--i){
		if(!vis[i]){
			if(flag) putchar(' ');
			printf("%d",i);
			k--;
			flag=true;
		}
	}
	cout<<endl;
	return 0;
}
