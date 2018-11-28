#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e7+10;
bool F[maxn];
int prime[maxn/10];
int num = 0;
int a[maxn/10];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	for(int i = 0; i < maxn; i++)
		F[i] = 1;
	F[0] = F[1] = 0;
	for(int i = 2; i < maxn; i++){
		if(F[i]){
            prime[num++] = i;
			for(int k = 2; k*i < maxn; k++)
				F[k*i] = 0;
        }
    }
}

int cal(long long int k){
    int cnt = 0;
    memset(a, 0, sizeof(a));
    for(int i = 0; prime[i] < k && i < num; i++){
        if(k % prime[i] == 0){
            a[cnt] = 0;
            while(k % prime[i] == 0){
                k /= prime[i];
                a[cnt]++;
            }
            cnt++;
        }
    }
    if(k > 1){
        a[cnt] = 1;
    }
    return cnt;
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        long long int n;
        cin>>n;
        int k = cal(n);
        long long int ans = 1;
        for(int i = 0; i <= k; i++){
            ans *= (2*(a[i]+1)-1);
        }   
        cout<<"Case "<<t<<": "<<ans/2+1<<endl; 
    }
}