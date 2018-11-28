#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		int a[100005];
		cin>>n;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int k = sqrt(abs(a[n-1]-a[0]));
		cout<<k<<endl;
	}
} 
