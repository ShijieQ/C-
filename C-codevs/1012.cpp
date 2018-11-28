#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
/*
int prime[maxn/10];
bool F[maxn];
int num = 0;
*/
int gcd(int a, int b){
    return b ? gcd(b, a%b):a;
}
/*
void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 0;
            }
        }
    }
}

int cal(int n){
    for(int i = 0; prime[i] < n && i < num; i++){
        int cnt = 0;
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
        }
    }

}
*/

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int ans = 0;
    if(y / x != int (y / x)){
        ans = 0;
    }
    else{
        for(int i = x; i <= y; i += x){
            for(int j = i; j <= y; j += x){
                if(gcd(i, j) == x && i*j/gcd(i, j) == y){
                    ans++;
                }
            }
        }
        ans = ans*2;
    }
    cout<<ans<<endl;
    return 0;
}
