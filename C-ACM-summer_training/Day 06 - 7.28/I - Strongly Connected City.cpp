#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int m, n;
	int flag = 0;
	char a[25], b[25];
	cin>>m>>n;
	getchar();
	for(int i = 0; i < m; i++){
		scanf("%c", &a[i]);
	}
	getchar();
	for(int i = 0; i < n; i++){
		scanf("%c", &b[i]);
	}
//	cout<<a[0]<<" "<<b[0]<<" "<<a[m-1]<<" "<<b[n-1]<<endl;
	if(a[0] == '>' && b[0] == '^' && a[m-1] == '<' && b[n-1] == 'v')	flag = 1;
	if(a[0] == '<' && b[0] == 'v' && a[m-1] == '>' && b[n-1] == '^')	flag = 1;
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
} 
