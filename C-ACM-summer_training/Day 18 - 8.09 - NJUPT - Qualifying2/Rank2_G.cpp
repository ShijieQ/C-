#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n%5 != 0)
		if((n/5+1)%2 == 0)
			cout<<"2"<<endl;
		else	
			cout<<"1"<<endl;
	else 
		if(n/5%2 == 0)
			cout<<"2"<<endl;
		else
			cout<<"1"<<endl;
} 

