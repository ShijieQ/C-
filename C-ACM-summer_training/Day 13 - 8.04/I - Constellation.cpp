#include<iostream>
#include<algorithm>
#define maxn 100000+5
#include<cmath>
using namespace std;

struct node{
	double x, y;
	int id;
}a[maxn];
/*
double area(struct node k, struct node b, struct node c){
	return 0.5*(k.x*(b.y-c.y)+b.x*(c.y-k.y)+c.x*(k.y-b.y));
}*/

bool area(int x){
	double dx=a[1].x-a[2].x,dy=a[1].y-a[2].y;
	double cx=a[1].x-a[x].x,cy=a[1].y-a[x].y;
	if(abs(dx*cy-dy*cx)<0.00001)return 0;
	return 1;
}

bool cmp(struct node k, struct node b){
	return k.x!=b.x?k.x<b.x:k.y<b.y;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i].x>>a[i].y;
		a[i].id = i;
	}
	sort(a+1, a+n+1, cmp);
//	cout<<a[1].id<<" "<<a[2].id<<" "<<a[3].id<<endl;
/*	for(int i = 1; i+2 <= n; i++){
		double k = area(a[i], a[i+1], a[i+2]);
		if(k == int(k)){
			cout<<a[i].id<<a[i+1].id<<a[i+2].id<<endl;
			return 0;
		}
	}*/
	for(int i = 3; i <= n; i++){
		if(area(i)){
			cout<<a[1].id<<" "<<a[2].id<<" "<<a[i].id<<endl;
			return 0;
		}
	}
}
