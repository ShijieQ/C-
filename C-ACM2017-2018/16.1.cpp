#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool judge(int x)
{
	for(int i = 1; i <= sqrt(x); i++)
	{
		int a = sqrt(x - i*i);
		if(i > a)
			break;
		if(a*a + i*i == x && a != 0)
			return true;
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,n;
		cin>>m>>n;
		int flag = 1;
		int sum = m*m + n*n;
		if(sum == 2)
		{
			cout<<"C"<<endl;
			continue;
		} 
		for(int i = 2; i < sum; i++)
		{
			if(sum%i)
				continue;
			int x = sum / i;
			if(judge(i) && judge(x))
			{
				cout<<"C"<<endl;
				flag = 0;
				break;
			}
		}
		if(flag)
			cout<<"P"<<endl;
	}
} 
