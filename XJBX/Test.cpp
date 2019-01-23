#include<bits/stdc++.h> 
using namespace std; 
string s; 
int main()
{ 	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int n,t,k=0,i; 
	cin>>n>>t>>s; 	 	
	for(i=0;i<n-1;i++) 
		if(s.substr(0,i+1)==s.substr(n-i-1)) 
			k=i+1; 
	cout<<"k = "<<k<<endl; 
	cout<<s; 	
	for(i=1;i<t;i++) 
		cout<<s.substr(k); 	 
	return 0;
}