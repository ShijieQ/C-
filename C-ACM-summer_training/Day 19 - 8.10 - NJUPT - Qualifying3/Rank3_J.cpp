#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int c;
	int x;
}a[1005];
int main(){
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF && (n || k)){
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].c);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].x);
		}
	}
} 
