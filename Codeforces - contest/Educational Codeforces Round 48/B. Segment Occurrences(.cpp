#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int first[1005];
	int ending[1005];
	memset(first, 0, sizeof(first));
	memset(ending, 0, sizeof(ending));
	int flag = 1;
	int lenn, lenm, q;
	cin>>lenn>>lenm>>q;
	string s, t;
	cin>>s>>t;
	s = " "+s;
	if(lenn < lenm)	
		flag = 0;
	else{
		for(int i = 1; i <= lenn-lenm+1; i++){
			if(s.substr(i, lenm) == t){
				first[i] = first[i-1] + 1;
				ending[i+lenm-1] = ending[i+lenm-2] + 1;
			}
			else{
				first[i] = first[i-1];
				ending[i+lenm-1] = ending[i+lenm-2];
			}
		}
	}
/*	for(int i = 1; i <= lenn; i++)
		cout<<first[i]<<" ";
	cout<<endl;
	for(int i = 1; i <= lenn; i++)
		cout<<ending[i]<<" ";
	cout<<endl;*/
	for(int i = 0; i < q; i++){
		int l, r;
		cin>>l>>r;
		if(!flag || r-l+1 < lenm || ending[r] - first[l-1] < 0)
			cout<<"0"<<endl;
		else
			cout<<ending[r] - first[l-1]<<endl;
	}
}
