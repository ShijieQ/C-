#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;	
		cin>>n;
		long long int ans = 0;
		n = n-1;
		for(int i = 1; i <= sqrt(n); i++){
			if(n % i == 0){
				ans++;
				if(i * i != n)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
}
