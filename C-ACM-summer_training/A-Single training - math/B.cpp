#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long int ll;
const int maxn = 40000+5;
int a[maxn];
bool F[maxn];
int prime[maxn/10];
int num_prime[maxn];
int num = 0;


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

int cal_prime(int n){
    for(int i = 1; i <= n; i++){
        num_prime[i] = 0;
        int tem = a[i];
        for(int j = 0; prime[j] < tem && j < num; j++){
            if(tem % prime[j] == 0){
                while(tem % prime[j] == 0){
                    tem /= prime[j];
                    num_prime[i]++;
                }
            }
        }
        if(tem > 1){
            num_prime[i]++;
        }
    }
}   

ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll ans = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ans;
}

void sol(int n){

}

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        cal_prime(n);
        
    }
}