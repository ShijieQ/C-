#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[1005];
	int maxa = -1, mina = 1000000001;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] > maxa)
			maxa = arr[i];
		if(arr[i] < mina)
			mina = arr[i];
	}
	for(int i=0;i<n;++i)
    {
        if(arr[i] %2 ==0) 
			cout<<arr[i]-1<<" ";
        else 
			cout<<arr[i]<<" ";
    }
	/*
	for(int i = mina; i <= maxa; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = 0; j < n; j++)
			{
				if(arr[j] == i)
					arr[j] = i-1;
			}
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(arr[j] == i)
					arr[j] = i+1;
			}
		}
	}*//*
	for(int i= 0; i < 2; i++)
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i] % 2 == 0)
				arr[i] = i-1;
			else
				arr[i] = i+1; 
		}
	}*//*
	cout<<arr[0];
	for(int i = 1; i < n; i++)
		cout<<" "<<arr[i];
	cout<<endl;*/
	cout<<endl;
 } 
