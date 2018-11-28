#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define maxn 100000+5
using namespace std;
int g[1005][1005]; 
int main(){
	ios::sync_with_stdio(false);
	int len_a, len_b, q_num;
	string a, b;
	cin>>len_a>>len_b>>q_num;
	cin>>a>>b;
	memset(a, 0, sizeof(a));
	int l, r;
	if(len_a < len_b){
		for(int i = 1; i <= q_num; i++){
			cout<<"0"<<endl;
		}
		return 0;
	}
	for(int i = 0; i < len_a; i++){
		if(a.substr(i, len_b) == b){
			g[i][i+len-1] = 1;
		}
	}
	for(int i = 1; i <= q_num; i++){
		cin>>l>>r;
	}
		cout<<ans<<endl;
	}
}
	
