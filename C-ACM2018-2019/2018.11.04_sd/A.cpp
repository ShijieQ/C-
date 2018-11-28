#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1e6+10;
ll GCD(ll a,ll b){
	while(b!=0){
		ll t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main(){
	ll x,y;
	scanf("%lld %lld",&x,&y);
	ll gcd,ans=0,A,B;
	gcd=GCD(x,y);
	x/=gcd,y/=gcd;
	vector<ll> a;
	for(ll i=2;i*i<=x;++i){
		while(x%i==0){
			x/=i;
			a.push_back(i);
		}
	}
	if(x>1) a.push_back(x);
	while(y!=0){
		ll g=y;
		vector<ll>::iterator it;
		for(it=a.begin();it!=a.end();it++){
			g=min(g,y%(*it));
		}
		ans+=g;
		y-=g;
		vector<ll> b;
		for(it=a.begin();it!=a.end();it++){
			if(y%(*it)==0){
				y/=(*it);
			}
			else 
				b.push_back((*it));
		}
		a.swap(b);
	}
	printf("%lld\n",ans);
	return 0;
}

