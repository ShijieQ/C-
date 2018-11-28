#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 20000+5;
int prime[maxn], F[maxn];
int num = 0;

void init(){
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < maxn; i++){
        F[i] = 1;
    }
    F[0] = F[1] = 0;
    for(int i = 2 ; i < maxn; i++){
        if(F[i]){
            prime[num++] = i;
            for(int k = 2; k*i < maxn; k++){
                F[i*k] = 0;
            }
        }
    }
}

int main(){
    init();
    int n;
    while(cin>>n){
        long long int cnt = 1;
        long long int ans = 0;
        int temp = num;
        for(int i = 0; i < num; i++){
            if(prime[i] > n){
                num = i-1;
                break;
            }
        }
        for(int i = 0, k = num; i <= k; k--){
            cnt = prime[k];
            while(i <= k && n >= cnt*prime[i]){
                cnt *= prime[i++];
            }
            ans++;
        }
        cout<<ans<<endl;
        num = temp;
    }
}