#include<iostream>
#include<algorithm>
#define MAXN 32
#define ull long long
#define mod 1000000000+7
using namespace std;

ull C[MAXN+1][MAXN+1];
void Initial()
{
	int i,j;
	for(i=0; i<=MAXN; ++i){
		C[0][i] = 0;
		C[i][0] = 1;
	}
	for(i=1; i<=MAXN; ++i){
		for(j=1; j<=MAXN; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	Initial();
	int n, m, t;
	cin>>n>>m>>t;
	ull ans = 0;
	for(int b = 4; b <= n; b++){
		int g = t-b;
		if(g < 1)
			break;
		else if(g > m)
			continue;
		else
			ans += C[n][b]*C[m][g];
	}
	cout<<ans<<endl;
}	
