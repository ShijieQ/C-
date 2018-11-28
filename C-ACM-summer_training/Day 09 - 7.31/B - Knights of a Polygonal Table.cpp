#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct people{
	long long int e;
	long long int coin;
}a[100005];

bool cmp(struct people c, struct people b){
	if(c.coin < b.coin)
		return false;
	else if(c.coin > b.coin)
		return true;
	else
		return c.e<b.e;
}
int main(){
	int n, num;
	cin>>n>>num;
	struct people b[100005];
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].e);
		b[i].e = a[i].e;
	}
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].coin);
		b[i].coin = a[i].coin;
	}
	sort(a, a+n, cmp);
/*	for(int i = 0; i < n; i++){
		cout<<a[i].e<<" "<<a[i].coin<<endl;
	}*/
	for(int i = 0; i < n; i++){
		long long int ans = b[i].coin;
		for(int j = 0,flag = 0; j < n && flag < num; j++){
			if(b[i].e > a[j].e){
				ans += a[j].coin;
				flag++;
			}
		}
		cout<<ans<<" ";
		ans = 0;
	}
}
