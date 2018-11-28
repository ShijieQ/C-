#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1e6+10;
int GCD(int a,int b){
	while(b!=0){
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main(){
	int a[5];
	int x=42;
	for(int i=1;i<=4;i++){
		scanf("%d",&a[i]);
	}
	int d=a[2]-a[1];
	if(a[3]-a[2]==d&&a[4]-a[3]==d){
		x=a[4]+d;
		printf("%d\n",x);
	}
	else{
		int q1,q2,gcd;
		gcd=GCD(a[1],a[2]);
		q1=a[1]/gcd;q2=a[2]/gcd;
		gcd=GCD(a[2],a[3]);
		if(q1==a[2]/gcd&&q2==a[3]/gcd){
			gcd=GCD(a[3],a[4]);
			if(q1==a[3]/gcd&&q2==a[4]/gcd){
				if(a[4]*q2%q1==0)
					x=a[4]*q2/q1;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}
