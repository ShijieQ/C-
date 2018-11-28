#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int m, n;
	cin>>m>>n;
	int a[30005];
	int step = 1;
	for(int i = 0; i < m-1; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; ; i++){
		step += a[step-1];
//		cout<<step<<endl;
		if(step > n){
			cout<<"NO"<<endl;
			return 0;
		}
		if(step == n){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
