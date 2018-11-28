#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define LL long long
#define ll long long 
using namespace std;

bool cmp(LL i, LL j){	
	return i>j;
}

int main(){
	int n;
	cin>>n;
	int a[100005];
	int count[100005];
	LL point[100005];
	memset(point, 0, sizeof(point));
	memset(count, 0, sizeof(count));
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		count[a[i]]++;
	}
	point[1] = count[1];
	for(int i = 2; i < 100005; i++){
		point[i] = max(point[i-1], 1LL*point[i-2]+1LL*i*count[i]);
	}
	sort(point, point+100005, cmp);
	cout<<point[0]<<endl;
} 
