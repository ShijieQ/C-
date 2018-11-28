#include<iostream>
#include<algorithm>
#define INF 1000000000
#define maxn 100000+5
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[maxn], b[maxn];
	int l = -INF, r = INF;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	char s[maxn];
	cin>>s;
	for(int i = 0; i < n; i++){
		b[i+1] = s[i] - '0';
	}
	int tem = 0;
	for(int i = 5; i <= n; i++){
		if(b[i] != tem){
			if(b[i])
				l = max(l, max(a[i]+1, max(a[i-1]+1, max(a[i-2]+1, max(a[i-3]+1, a[i-4]+1)))));
//				l = max(l, a[i]+1, a[i-1]+1, a[i-2]+1, a[i-3]+1, a[i-4]+1);
			else
				r = min(r, min(a[i]-1, min(a[i-1]-1, min(a[i-2]-1, min(a[i-3]-1, a[i-4]-1)))));
//				r = min(r, a[i]-1, a[i-1]-1, a[i-2]-1, a[i-3]-1, a[i-4]-1);
			tem = b[i];
		}
	}
	cout<<l<<" "<<r<<endl;
} 
