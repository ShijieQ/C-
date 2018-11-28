#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
	} 
	for(int i = 1; i <= n; i++){
		if(i%2)	cout<<1;
		else cout<<0;
	}
	cout<<endl;
}
