#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long maxn = 1e6+5;
int F[maxn];
int prime[maxn];
int num = 0;

void init(){
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

int cal(long long a){
    long long int ans = 1;
    for(int i = 0; prime[i] < a && i < num; i++){
        int cnt = 0;
        if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
        }
        ans *= (1 + cnt);
    }
    if(a > 1)//考虑到爆prime[]的上限
        ans *= 2;
    return ans;
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        long long a, b;
        cin>>a>>b;
        long long tans = 0, ans = 0;
        if(b*b >= a){
            ans = 0;
        }
        else{
            for(long long i = 1; i < b; i++){
                if(a % i == 0)
                    tans++;
            }
            ans = cal(a)/2 - tans;
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}