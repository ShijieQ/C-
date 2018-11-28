#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int fp[100005];
int num[100005];
int begining[100005];
int main()
{
	int n;
	int Case = 0;
	cin>>n;
	int flag = 1;
	while(n--)
	{
		if(flag)
			flag = 0;
		else
			cout<<endl;
		int ending = 1;
		int number;
		begining[1] = 1;
		cin>>number;
		for(int i = 1; i <= number; i++)
			cin>>num[i];
		fp[1] = num[1];
		for(int i = 2; i <= number; i++)
		{
			fp[i] = max(fp[i-1] + num[i],num[i]);
			if(fp[i-1] + num[i] >= num[i])
				begining[i] = begining[i-1];
			else
				begining[i] = i;
			if(fp[i] > fp[ending])
				ending = i;
		}
		cout<<"Case "<<++Case<<":"<<endl;
		cout<<fp[ending]<<" "<<begining[ending]<<" "<<ending<<endl;
	}
	return 0;
}
