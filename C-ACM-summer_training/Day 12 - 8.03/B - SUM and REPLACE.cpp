#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#define LL long long 
#define maxn 300005
using namespace std;
int a[maxn];
int D[maxn];

struct node{
	int t,l,r;
}query[maxn];

void init(){
	
} 
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &query[i].t, &query[i].l, &query[i].r);
	
} 


