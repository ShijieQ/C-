#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1e6+10;
struct node{
	int k,c;
	bool operator<(const node&b)const{
		return c<b.c;
	}
}a[110];
ll p[110];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].k,&a[i].c);
	}
	sort(a,a+n);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%I64d",&p[i]);
	}
	for(int i=t;i>1;i--){
		p[i]-=p[i-1];
	}
	ll ans=0;
	int ant=0;
	for(int i=1;i<=t;i++){
		ll cur=0;
		while(p[i]>0&&ant<n){
			if(p[i]>a[ant].k){
				cur+=(ll)a[ant].k*(ll)a[ant].c;
				p[i]-=a[ant].k;
				ant++;
			}
			else {
				cur+=p[i]*a[ant].c;
				a[ant].k-=p[i];
				break;
			}
		}
		ans+=cur*i;
	}
	ll cur=0;
	for(;ant<n;ant++){
		cur+=(ll)a[ant].k*(ll)a[ant].c;
	}
	ans+=cur*(t+1);
	printf("%I64d\n",ans);
	return 0;
}
