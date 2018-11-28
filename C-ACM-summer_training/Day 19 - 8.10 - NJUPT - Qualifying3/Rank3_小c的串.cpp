#include<iostream>
#include<algorithm>
using namespace std;
char a[300005];
int main(){
	ios::sync_with_stdio(false);
	int n, x, y;
	cin>>n>>x>>y;
	cin>>a+1;
	int flag = 0;
	long long int ans = 0;
	if(a[1] == '0')
		flag++;
	for(int i = 1; i <= n-1; i++){
		if(a[i] == '1' && a[i+1] == '0')
			flag++;
	}
	cout<<min(1LL*flag*y, 1LL*(flag-1)*x+y)<<endl;
}
