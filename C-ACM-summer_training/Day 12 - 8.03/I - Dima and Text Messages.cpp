#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string a,b;
	a = "<3";
	int n;
	cin>>n;
	while(n--){
		string tem;
		cin>>tem;
		a += tem+"<3";
	}
	cin>>b;
//	cout<<a<<endl<<b<<endl;
	int flag = 0;
	int k = 0;
	for(int i = 0; i < b.size(); ){
		if(a[k] == b[i]){
			k++;
			i++;
		}
		else{
			if((b[i] >= 'a' && b[i] <= 'z') || (b[i] >= '0' && b[i] <= '9') || b[i]=='<' || b[i]=='>')
				i++;
		}
	}
	if(k != a.size())
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
	
}
