#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e7+10;
bool F[maxn];
int prime[5000000];
int cnt = 0;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < maxn; i++){
        F[i] = 1;
    }
    F[0] = F[1] = 0;
    for(int i = 2; i < maxn; i++){
        if(F[i]){
            prime[++cnt] = i;
            for(int k = 2; k*i < maxn; k++){
                F[k*i] = 0;
            }
        }
    }
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        int n;
        cin>>n;
        int ans = 0;
        for(int i = 1; prime[i] <= n-prime[i] && i <= cnt; i++){
            int k = n-prime[i];
            if(F[k])
                ans++;
        }
        if(n == 4)
            ans = 1;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}