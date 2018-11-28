#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000000+100;
const int mod = 1000000007;
bool F[maxn];
int prime[maxn];
int D[maxn];
int num = 0;

void init(){
    for(int i = 2; i < maxn; i++){
        F[i] = 1;
    }
    D[0] = D[1] = 1;
    F[0] = F[1] = 0;
    for(int i = 2; i < maxn; i++){
        if(F[i]){
            prime[num++] = i;
            for(int k = 2; k*i < maxn; k++)
                F[i*k] = 0;
        }
    }
    for(int i = 1; i < maxn; i++){
    	if(F[i])
    		D[i] = D[i-1];
    	else{
        	D[i] = (1LL*D[i-1]*i)%mod;
		}
	}
}

long long cal(int a){
    int k = a;
    long long int ans = 1;
    for(int i = 0; prime[i] <= a/2 && i < num; i++){
    	int cnt = 0;
        int a = k;
        while(a >= prime[i]){
            a /= prime[i];
            cnt += a;
        }
        if(!(cnt&1)){
            ans = (ans*prime[i])%mod;
        }
    }
    return ans;
}

int main(){
    init();
    int n;
    while(scanf("%d", &n) != EOF && n){
		long long int ans = (cal(n)*D[n])%mod;
		printf("%lld\n", ans);
    }
}