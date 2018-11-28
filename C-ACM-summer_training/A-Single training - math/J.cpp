#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
// In fact, you just need 1e6.
const int maxn = 1e7+10;
bool F[maxn];
int prime[maxn/10];
int num = 0;

int gcd(int a, int b){
    return b ? gcd(b, a%b):a;
}

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

int sol(long long int a){
    bool flag = 0;
    if(a < 0){
        a = -a;
        flag = 1;
    }
    int ans = 0;
    for(int i = 0; prime[i] < a && i < num; i++){
        if(a % prime[i] == 0){
			int cnt = 0;
            while(a % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
            if(ans)
                ans = gcd(ans, cnt);
            else
                ans = cnt;
        }
    }
    if(a > 1){
        ans = 1;
    }
    if(flag){
        while(ans % 2 == 0){
            ans /= 2;
        }
    }
    return ans;
}

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        long long int a;
		/* because the range is less than 2^32, we should use long long instead of int. 
			if not, it will TLE.
			*/
        scanf("%lld", &a);
        printf("Case %d: %d\n", t, sol(a));
    }
}