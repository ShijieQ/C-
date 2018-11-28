#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int MX = 100005; 
const int maxx = 100005;
const int mod = 1000000007;
long long inv[MX],f[MX];

struct node{
	int R;
	int L;
	int id;
	int k;
	long long anss;
	bool operator < (const node &a) const
    {
        return (k == a.k) ? (R<a.R):(k<a.k);
    }
}a[maxx];

long long qpow(long long a,long long b){//或许是求对数 
	long long res = 1;
	while(b){
		if(b & 1) 
			res = (res*a) % mod;
		a = (a*a) % mod;
		b >>= 1;
	}
	return res;
}

void init(){//预处理 
    f[1] = 1;
    for(int i = 2; i < MX; i++) 
		f[i] = (f[i-1] * i) % mod;
    for(int i = 1; i < MX; i++) 
		inv[i] = qpow(f[i],mod-2);
}

long long C(int n,int m){//计算组合数 
    if(n < 0 || m < 0 || m > n) return 0;
    if(m == 0 || m == n) return 1;
    return f[n]*inv[n-m]%mod*inv[m]%mod;
}

bool cmp(struct node a, struct node b){
	return a.id < b.id;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	init();
	int tem = int (sqrt(MX));
	for(int i = 1; i <= T; i++){
		cin>>a[i].R>>a[i].L;
		a[i].id = i; 
		a[i].k = a[i].L / tem;
	}
	sort(a+1, a+T+1);
	int left = 0;
	int right = 1;
	long long  sum = 1;
	for(int i = 1; i <= T; i++){
		while(right<a[i].R){
            sum = (2*sum - C(right, left)+mod)%mod;
            right++;
        }
		while(left>a[i].L){
        	sum = (sum - C(right, left)+mod)%mod;
			left--;
        }
		while(left<a[i].L){
			sum = (sum + C(right, left+1))%mod;
			left++;
		}
        while(right>a[i].R){
			sum = ((sum + C(right-1, left))/2)%mod;
			right--;
        }
        a[i].anss = sum;
	}
	sort(a+1, a+T+1, cmp);
	for(int i = 1; i <= T; i++){
		cout<<a[i].anss<<endl;
	}
	return 0;
}
