/*	TLE´úÂë
	*/ 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int id;
	int num;
}a[100005];
int main()
{
	int n;
	cin>>n;
	queue<node> q;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].num);
		a[i].id = i;
		q.push(a[i]);
	}
	struct node k = q.front();
	int c = 0;
	while(--k.num){
		q.pop();
		q.push(k);
		c = k.id;
		k = q.front();
	}
	if(c==0)
		cout<<n<<endl;
	else
		cout<<c<<endl;
}
