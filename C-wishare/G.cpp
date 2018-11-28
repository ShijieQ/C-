#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	int d[3];
	while(scanf("%d %d %d",&a,&b,&c) != EOF)
	{
		d[0] = a;
		d[1] = b;
		d[2] = c;
		sort(d,d+3);
		a = d[0];
		b = d[1];
		c = d[2];
//		cout<<d[0]<<d[1]<<d[2]<<endl;
		if(a == 1 && b == 2 && c == 3)
			cout<<"0"<<endl;
		if(a == 1 && b == 2 && c == 4)
			cout<<"0"<<endl;
		if(a == 1 && b == 2 && c == 5)
			cout<<"3"<<endl;
		if(a == 1 && b == 2 && c == 6)
			cout<<"3"<<endl;
		if(a == 1 && b == 3 && c == 4)
			cout<<"2"<<endl;
		if(a == 1 && b == 3 && c == 5)
			cout<<"0"<<endl;
		if(a == 1 && b == 3 && c == 6)
			cout<<"2"<<endl;
		if(a == 1 && b == 4 && c == 5)
			cout<<"0"<<endl;
		if(a == 1 && b == 4 && c == 6)
			cout<<"2"<<endl;
		if(a == 1 && b == 5 && c == 6)
			cout<<"3"<<endl;
		if(a == 2 && b == 3 && c == 4)
			cout<<"1"<<endl;
		if(a == 2 && b == 3 && c == 5)
			cout<<"1"<<endl;
		if(a == 2 && b == 3 && c == 6)
			cout<<"0"<<endl;
		if(a == 2 && b == 4 && c == 5)
			cout<<"1"<<endl;
		if(a == 2 && b == 4 && c == 6)
			cout<<"0"<<endl;
		if(a == 2 && b == 5 && c == 6)
			cout<<"3"<<endl;
		if(a == 3 && b == 4 && c == 5)
			cout<<"1"<<endl;
		if(a == 3 && b == 4 && c == 6)
			cout<<"2"<<endl;
		if(a == 3 && b == 5 && c == 6)
			cout<<"0"<<endl;
		if(a == 4 && b == 5 && c == 6)
			cout<<"0"<<endl;		
	}
}
