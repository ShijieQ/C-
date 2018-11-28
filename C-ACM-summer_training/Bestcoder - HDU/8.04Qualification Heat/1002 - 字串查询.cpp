#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define maxn 100005
using namespace std;
map<char, int> mp;
pair<char, char> pr;
string s;

struct node{
	int l, r;
	int id;
	int ans;
	bool operator <(const node b) const{
		return l!=b.l?l<b.l:r<b.r;
	}
}query[maxn];

bool cmp(struct node a, struct node b){
	return a.id < b.id;
}

char find(int l, int r){
	char minn = s[l];
	for(int i = l+1; i <= r; i++){
		if(minn > s[i])
			minn = s[i];
	}
	return minn;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i = 1; i <= T; i++){
		cout<<"Case #"<<i<<":"<<endl; 
		int len, q;
		cin>>len>>q;
		cin>>s;
		s = " " + s;
		for(int i = 1; i <= q; i++){
			cin>>query[i].l>>query[i].r;
			query[i].id = i;
		}
		sort(query+1, query+q+1);
		int l = 1;
		int r = 2;
		if(s[l] < s[r]){
			pr.first = s[l];
			pr.second = s[r];
		}
		else if(s[l] > s[r]){
			pr.first = s[r];
			pr.second = s[l];
		}
		else
			pr.first = s[l];
		mp[s[l]]++;
		mp[s[r]]++;
		for(int i = 1; i <= q; i++){
			if(query[i].l == query[i].r){
				query[i].ans = 1;
				continue;
			}
			while(l > query[i].l){
				l--;
				mp[s[l]]++;
				if(s[l] < pr.first)
					pr.first = s[l];
				else if(s[l] < pr.second)
					pr.second = s[l];
			}
			while(r < query[i].r){
				r++;
				mp[s[r]]++;
				if(s[r] < pr.first)
					pr.first = s[r];
				else if(s[r] < pr.second)
					pr.second = s[r];
			}
			while(l < query[i].l){
				mp[s[l]]--;
				if(!mp[s[l]])
					pr.first = find(l+1, r);
				l++;
			}
			while(r > query[i].r){
				mp[s[r]]--;
				if(!mp[s[l]])
					pr.first = find(l, r-1);
				r--;
			}
			query[i].ans = mp[pr.first];
		}
		sort(query+1, query+q+1,cmp);
		for(int i = 1; i <= q; i++){
			cout<<query[i].ans<<endl;
		}
	}
}
