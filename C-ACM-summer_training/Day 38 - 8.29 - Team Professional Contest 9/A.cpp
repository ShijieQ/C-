#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <algorithm>
#include <stdlib.h>
 
#define N 10001
#define M 101000
#define inf 107374182
#define ll int
 
using namespace std;
 
//双向边，注意RE 注意这个模版是 相同起末点的边 合并而不是去重
//注意 起点<终点&&终点必须为最大点标 && 点标不要太分散
struct Edge{
	int from, to, flow, cap, nex, cost;
}edge[M*2];
 
int head[N], edgenum;
void addedge(int u,int v,int cap,int cost){//网络流要加反向弧
	Edge E={u, v, 0, cap, head[u], cost};
	edge[edgenum]=E;
	head[u]=edgenum++;
 
	Edge E2={v, u, 0, 0, head[v], -cost}; //这里的cap若是单向边要为0
	edge[edgenum]=E2;
	head[v]=edgenum++;
}
int D[N], P[N], A[N];
bool inq[N];
bool BellmanFord(int s, int t, int &flow, int &cost){
	for(int i=0;i<=t;i++) D[i]= inf;
 
	memset(inq, 0, sizeof(inq));
	D[s]=0;  inq[s]=1; P[s]=0; A[s]=inf;
 
	queue<int> Q;
	Q.push( s );
	while( !Q.empty()){
		int u = Q.front(); Q.pop();
		inq[u]=0;
		for(int i=head[u]; i!=-1; i=edge[i].nex){
			Edge &E = edge[i];
			if(E.cap > E.flow && D[E.to] > D[u] +E.cost){
				D[E.to] = D[u] + E.cost ;
				P[E.to] = i;
				A[E.to] = min(A[u], E.cap - E.flow);
				if(!inq[E.to]) Q.push(E.to) , inq[E.to] = 1;
			}
		}
	}
	if(D[t] == inf) return false;
	flow += A[t];
	cost += D[t] * A[t];
	int u = t;
	while(u != s){
		edge[P[u]].flow += A[t];
		edge[P[u]^1].flow -= A[t];
		u = edge[P[u]].from;
	}
	return true;
}
 
int Mincost(int s,int t){//返回最小费用
	int flow = 0, cost = 0;
	while(BellmanFord(s, t, flow, cost));
	return cost;
}
 
int n, m;
int main(){
	int i, j, u, v, cost;
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		memset(head,-1,sizeof(head)); edgenum =0;
		while(m--){
			scanf("%d %d %d",&u,&v,&cost); 
			addedge(u,v,1,cost);
			addedge(v,u,1,cost);
		}
		addedge(n,n+1,2,0);
		int ans = Mincost(1,n+1);
		if(edge[edgenum-2].flow == 2)printf("%d\n",ans);
		else puts("Back to jail");
	}
	return 0;
}
/*
2
1
1 2 999
3
3
1 3 10
2 1 20
3 2 50
9
12
1 2 10
1 3 10
1 4 10
2 5 10
3 5 10
4 5 10
5 7 10
6 7 10
7 8 10
6 9 10
7 9 10
8 9 10
0
*/
