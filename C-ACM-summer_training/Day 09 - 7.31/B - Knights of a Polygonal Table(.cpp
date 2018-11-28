#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct people{
	long long int e;
	long long int coin;
	long long pos;
	long long _coin;
	bool operator < (const people & a) const
    {
        return coin < a.coin;
    }
}a[100005], tem[100005];

bool cmp1(struct people c, struct people b){
	if(c.e > b.e)
		return true;
	else 
		return false;
}

bool cmp2(struct people c, struct people b){
	if(c.coin > b.coin)
		return true;
	else 
		return false;
}

bool cmp3(struct people c, struct people b){
	if(c.e < b.e)
		return true;
	else
		return false;
}

bool cmp4(struct people c, struct people b){
	if(c.pos < b.pos)
		return true;
	else
		return false;
}

int main(){
	int n, num;
	cin>>n>>num;
	priority_queue<people> q;
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].e);
		a[i].pos = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].coin);
		a[i]._coin = a[i].coin;
	}
	sort(a, a+n, cmp3);
	for(int i = 0; i < n; i++){
		int flag = 0;	
//		cout<<q.size()<<endl;
		while(q.size() && flag < num){
			struct people k = q.top();
			q.pop();
//			cout<<k.coin<<endl;
			tem[flag++] = k;
			a[i]._coin += k.coin;
		}
		q.push(a[i]);
//		cout<<"****"<<flag<<endl;
		for(int j = 0; j < flag; j++)
			q.push(tem[j]);
/*		while(q.size()){
			struct people k = q.top();
			q.pop();
			cout<<k.e<<" ";
		}
		cout<<endl;*/
	}
/*	while(q.size()){
		struct people k = q.top();
		q.pop();
		cout<<k.coin<<" ";
	}*/
	sort(a, a+n, cmp4);
	for(int i = 0; i < n; i++)
		cout<<a[i]._coin<<" ";
	cout<<endl;
}
