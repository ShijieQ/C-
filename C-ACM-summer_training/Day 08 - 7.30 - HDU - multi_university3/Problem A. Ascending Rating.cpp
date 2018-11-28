#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 10000005
using namespace std;
int a[maxn];
struct index{
	int maxx;
	int count;
}indexs[maxn];

void sol(int a[], int n){
	int Max = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > indexs[i-1].maxx){
			indexs[i].maxx = a[i];
			indexs[i].count = indexs[i-1].count + 1;
		}
		else{
			indexs[i].maxx = indexs[i-1].maxx;
			indexs[i].maxx = indexs[i-1].count;
		}
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
//		int a1[maxn];
		int n, m, k, p, q, r, MOD;
		scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &MOD);
		for(int i = 1; i <= k; i++){
			scanf("%d", &a[i]);
		}
		for(int i = k+1; i <= n; i++){
			a[i]=(p*a[i-1]%MOD + q*i%MOD + r%MOD)%MOD;
		}
		sol(a, n);
		int A = 0, B = 0;
		for(int i = 1; i <= n-m+1; i++){
			B += (indexs[i+m-1].count - indexs[i].count) ^ i;
			A += (indexs[i+m-1].maxx - indexs[i].maxx) ^ i;
		}
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}
