#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int m, n;
	cin>>n>>m;
	if(n == 1){
		cout<<1<<endl;
		return 0;
	}
	if(m <= n/2)
		cout<<m+1<<endl;
	else
		cout<<m-1<<endl;
	return 0;
}
