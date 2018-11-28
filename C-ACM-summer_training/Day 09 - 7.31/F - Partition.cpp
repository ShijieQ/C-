#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[105];
	int ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i]>0)	ans+=a[i];
		else 	ans-=a[i];
	}
	cout<<ans<<endl;
}
