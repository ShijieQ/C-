#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 35
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long int mindamage,nowdamage = 0,maxdamage = 0;
		cin>>mindamage;
		int flag = 0,flag1 = 1;
		char a[maxn];
		int s[maxn];
		long long int sdamage[maxn];
		int numd = 0, nums = 0;
		scanf("%s", a);
		int leng = strlen(a);
		for(int i = 0,j = 0; i < leng; i++)
		{
			if(a[i] == 'D')
				numd++;
			else
			{
				s[j++] = numd;
				nums++;
			}
		}//SDDDSS
		for(int i = 0; i < nums; i++)
		{
			sdamage[i] = pow(2.0,s[i]*1.0);
			nowdamage += sdamage[i];
		}
		for(int i = leng -1; i >= 0; i--)
		{
			if(a[i] == 'S' && i+1 < leng && a[i+1] == 'D')
			{
				for(int j = i; j < leng-1 && a[j+1] != 'S'; j++)
				{
					a[i] = 'D';
					a[i+1] = 'S';
					nowdamage -= sdamage[nums-1];
					sdamage[nums-1] *= 2;
					nowdamage += sdamage[nums-1];
					flag++;
				}
				nums--;
			}
			if(nowdamage >= mindamage)
			{
				cout<<flag<<endl;
				flag1 = 0;
				break;
			}
		}
		if(flag1)
			cout<<"IMPOSSIBLE"<<endl;
	}
}
