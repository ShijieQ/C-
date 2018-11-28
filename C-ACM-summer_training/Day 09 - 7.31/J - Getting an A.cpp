#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int n;
	int a[105];
	cin>>n;
	int flag = 0;
	double ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ans += a[i];
	}
	while(ans*10/n < 45){
		sort(a, a+n);
		ans -= a[0];
		a[0] = 5;
		ans += 5;
		flag++;
	}
	cout<<flag<<endl;
}
