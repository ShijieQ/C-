/* wa 
	²»ÄÜ½×³Ë¼ÆËã
	*/ 
#include<iostream>
#include<algorithm>
#define MX 35
#define ull unsigned long long
#define mod 1000000000
using namespace std;

ull f[MX];

void init(){
    f[1]=1;
    for(int i=2;i<MX;i++) f[i]=(f[i-1]*i);
}

ull C(int n,int m){
    if(n < 0 || m < 0 || m > n) return 0;
    if(m == 0 || m == n) return 1;
    return f[n]/f[m]/f[n-m];
}

int main(){
	ios::sync_with_stdio(false);
	init();
	for(int i = 1; i <= 30; i++){
		cout<<f[i]<<endl;
	}
	int n, m, t;
	cin>>n>>m>>t;
	ull ans = 0;
	for(int b = 4; b <= n; b++){
		int g = t-b;
		if(g < 1)
			break;
		else
			ans += (C(n, b)*C(m, g));
	}
	cout<<ans<<endl;
}	
