#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+5;
bool F[maxn];
int prime[maxn];
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

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        long long int a, b;
        scanf("%lld%lld", &a, &b);
        long long int cnt = 0;
        if(b < maxn){
            for(int i = 0; i < num; i++){
                if(prime[i] <= b && prime[i] >= a){
                    cnt++;
                }
                if(prime[i] > b)
                    break;
            }
        }
        else{
            memset(F, 0, sizeof(F));
            for(int i = 0; i < num; i++){
                long long int j;
                if(1LL*prime[i]*prime[i] > b)
                    break;
                if(a % prime[i] == 0)
                    j = a;
                else
                    j = (a/prime[i] + 1)*prime[i];
                while(j <= b){
                    F[j-a] = 1;
                    j += prime[i];
                }
            }
            for(int i = 0; i <= b-a; i++){
                if(!F[i]){
                    cnt++;
                }
            }
            if(a == 1)
                cnt--;
        }
        printf("Case %d: %d\n", t, cnt);
    }
}
