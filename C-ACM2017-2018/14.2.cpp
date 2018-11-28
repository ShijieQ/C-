#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int X = 1,Y = 1;
	int n;
	cin>>n;
	int t,x,y;
	while(n--)
	{
		scanf("%d %d %d",&t,&x,&y);
		if(t == 1)
		{
			long long int tempx = X;
			X += x;
			if(tempx*X<=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			tempx = X;
			X -= y;
			if(tempx*X<=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if(t == 2)
		{
			long long int tempx = Y;
			Y += x;
			if(tempx*Y<=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			tempx = Y;
			Y -= y;
			if(tempx*Y<=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl<<"("<<X<<", "<<Y<<")"<<endl;
}
