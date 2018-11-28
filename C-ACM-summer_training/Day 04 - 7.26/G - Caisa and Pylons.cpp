#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[100005];
	cin>>n;
	int mon = 0;
	int hei = 0;
	int eng = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > hei)
		{
			if(eng < a[i]-hei)
			{
				mon += a[i]-hei-eng;
				eng = 0;
				hei = a[i];
			}
			else
			{
				eng -= a[i] - hei;
				hei = a[i];
			}
		}
		else
		{
			eng += hei - a[i];
			hei = a[i];
		}
	}
	cout<<mon<<endl;
}
