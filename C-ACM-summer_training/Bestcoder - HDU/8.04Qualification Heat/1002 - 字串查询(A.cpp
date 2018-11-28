#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define maxn 100005
using namespace std;
int a[maxn][27];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i = 1; i <= T; i++){
		int mp[27];
		cout<<"Case #"<<i<<":"<<endl; 
		int len, q;
		cin>>len>>q;
		string s;
		cin>>s;
		s = " " + s;
		for(int i = 0; i <= len; i++){
			for(int j = 0; j < 27; j++){
				a[i][j] = 0;
				mp[j] = 0;
			}
		}
		for(int i = 1; i <= len; i++){
			int k = s[i] - 'A'+1;
			mp[k]++;
			for(int j = 1; j <= 26; j++)
				a[i][j] = mp[j];
		}/*
		for(int i = 1; i <= len; i++){
			for(int j = 1; j <= 26; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i = 1; i <= q; i++){
			int l, r;
			cin>>l>>r;
/*			if(l == r){
				cout<<"1"<<endl;
				break;
			}*/
			for(int j = 1; j <= 26; j++){
				if(a[r][j]-a[l-1][j] > 0){
					cout<<a[r][j]-a[l-1][j]<<endl;
					break;
				}
			}
		}
	}
}
