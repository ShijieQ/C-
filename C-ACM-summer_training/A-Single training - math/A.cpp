#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10005;
const int maxx = 1e6+1000;
const int INF = 0x3f3f3f3f;
int a[maxn];
int prime[maxx];

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin>>T;
    for(int k = 1; k <= T; k++){
        int n;
        cin>>n;
        long long int sum = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = a[i]+1; j < maxx; j++){
                if(prime[j] == 1){
                    sum += j;
                    break;
                }
            }
        }
        cout<<"Case "<<k<<": "<<sum<<" Xukha"<<endl;
    }
    return 0;
}