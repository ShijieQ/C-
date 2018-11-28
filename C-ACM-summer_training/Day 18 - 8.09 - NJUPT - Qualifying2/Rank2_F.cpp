#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 10000+5
#define INF 0x3f3f3f3f
using namespace std;
int a[maxn];
int main(){
	ios::sync_with_stdio(false); 
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		q.push(a[i]);
	}
	long long int ans = 0;
	for(int i = 1; i <= n-1; i++){
		int tem1 = q.top();
		q.pop();
		int tem2 = q.top();
		q.pop();
//		cout<<tem1<<" "<<tem2<<endl;
		ans += tem1 + tem2;
		q.push(tem1+tem2);
	}
	cout<<ans<<endl;
}
