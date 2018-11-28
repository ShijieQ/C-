#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int p,q;
		cin>>p>>q;
		int m,n;
		int flag = 0;
		for(m = -150; m <= 150; m++)
		{
			for(n = -150; n <= 150; n++)
			{
				int c = m*m + n*n;
				if(c == 0)
					continue;
				int a = m*p + n*q;
				int b = m*q - n*p;
				if(a%c==0 && b%c==0)
					flag++;
			}
		}
		if(flag == 8)
			cout<<"P"<<endl;
		else
			cout<<"C"<<endl;
	}
}
