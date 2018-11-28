#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define maxn 100000+5
using namespace std;

struct node{
	int r;
	int l;
	int ans;
}q[maxn], k[maxn];
map<int, int> mp[maxn];

bool cmp(struct node a, struct node b){
	if(a.l < b.l)
		return true;
	else if(a.l > b.l)
		return false;
	else
		return a.r < b.r;
}
int main(){
	ios::sync_with_stdio(false);
	int len_a, len_b, q_num;
	string a, b;
	cin>>len_a>>len_b>>q_num;
	cin>>a>>b;
	for(int i = 1; i <= q_num; i++){
		cin>>q[i].l>>q[i].r;
		q[i].ans = i;
	}
	sort(q+1, q+q_num+1, cmp);
	int nj = 0;
	for(int i = 0; i < len_a; i++){
		if(a.substr(i, i+len_b-1) == b){
			k[nj].l = i+1;
			k[nj++].r = i+len_b;
		}
	}
	if(len_a < len_b){
		for(int i = 1; i <= q_num; i++)
			cout<<"0"<<endl;
	}
	else{
		for(int i = 1; i <= T; i++){
		while(right<a[i].R){
            sum = (2*sum - C(right, left)+mod)%mod;
            right++;
        }
		while(left>a[i].L){
        	sum = (sum - C(right, left)+mod)%mod;
			left--;
        }
		while(left<a[i].L){
			sum = (sum + C(right, left+1))%mod;
			left++;
		}
        while(right>a[i].R){
			sum = ((sum + C(right-1, left))/2)%mod;
			right--;
        }
	}
	
}
