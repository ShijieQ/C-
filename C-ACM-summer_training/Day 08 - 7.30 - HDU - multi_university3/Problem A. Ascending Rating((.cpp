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
	int ending;
}indexs[maxn];

void sol(int a[], int c, int m){
	int Max = 0, ans = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] > a[i+1]){
			ans++;
		}
		else{
			index[i-ans+1].ending = i;
			Max = i+1;
			ans = 1;
		}
	}
	indexs[c].count = ans;
	indexs[c].maxx = Max;
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
		for(int i = 1; i+m-1 <= n; i++){
			sol(a, i, m);
		}
		int A = 0, B = 0;
		for(int i = 1; i <= n-m+1; i++){
			B += indexs[i].count ^ i;
			A += indexs[i].maxx ^ i;
		}
		cout<<A<<" "<<B<<endl;
	}
	return 0;
}
