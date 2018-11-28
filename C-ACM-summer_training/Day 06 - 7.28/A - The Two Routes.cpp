#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 405
int road1[maxn][maxn], road2[maxn][maxn];
/*
void Floyd(int road[][maxn], int n){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				road[i][j] = min(road[i][j], road[i][k]+road[k][j]);
			}
		}
	}
}
*/
int main(){
	int m, n;
//	cout<<INF<<endl;
	cin>>m>>n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			road1[i][j] = INF;
			road2[i][j] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		road1[a][b] = 1;//1表示两节点之间存在铁路, 且权值为1
		road1[b][a] = 1;
		road2[a][b] = INF;
		road2[b][a] = INF;
	}
	/*
	Floyd(road1, m);
	Floyd(road2, m);*/
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				road1[i][j] = min(road1[i][j], road1[i][k]+road1[k][j]);
			}
		}
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				road2[i][j] = min(road2[i][j], road2[i][k]+road2[k][j]);
			}
		}
	}
	if(road1[1][m] >= INF || road2[1][m] >= INF){
		cout<<"-1"<<endl;
	}
	else{
		cout<<max(road1[1][m], road2[1][m])<<endl; 
	} 
	return 0;
}
