#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10005;
const int maxx = 1e7+1000;
const int INF = 0x3f3f3f3f;
int a[maxn];
int prime[maxx];
int dp[maxx];

void init(){
	int i,k;
	for(i = 0; i < maxx; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(i= 2; i < maxx; i++)
		if(prime[i] == 1)
			for(k = 2; k*i < maxx; k++)
				prime[k*i] = 0;
}

int main(){
    freopen("c.in", "r", stdin);
    init();
    dp[2] = 1;
    for(int i = 2; i < maxx; i++){
        if(prime[i]){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = dp[i-1];
        }
    }
    int a, b;
    int flag = 0;
    while(scanf("%d %d", &a, &b) != EOF){
        if(flag)
            cout<<endl<<dp[b] - dp[a-1]<<endl;
        else{
            cout<<dp[b] - dp[a-1]<<endl;
            flag = 1;
        }
    }
}