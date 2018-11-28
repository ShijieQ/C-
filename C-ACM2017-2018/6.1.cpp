#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,a,b;
		long long int sum[3] = {0};
		cin>>N>>a>>b;
		sum[0] = a;
		sum[1] = b;
		for(long long int i = 2; i < N; i++)
		{
			sum[i%3] = (sum[(i-1)%3] % 2147493647 + sum[(i-2)%3] % 2147493647 + (i*i*i*i) % 2147493647) % 2147493647;
		}
		cout<<sum[(N-1)%3]<<endl;
	}
	return 0;
} 
