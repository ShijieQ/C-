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
		int mindamage,nowdamage = 0,maxdamage = 0;
		cin>>mindamage;
		int flag = 0,flag1 = 1;
		int c = 1;
		char a[maxn];
		int s[maxn];
		int sdamage[maxn];
		int numd = 0, nums = 0;
		scanf("%s", a);
		int leng = strlen(a);
		for(int i = 0,j = 0; i < leng; i++)
		{
			if(a[i] == 'D')
			{
				numd++;
				c *= 2;
			}
			else
			{
				sdamage[j] = c;
				s[j++] = numd;
				nums++;
			}
		}//SDDDSS
		for(int i = 0; i < nums; i++)
			nowdamage += sdamage[i];
		if(nowdamage >= mindamage)
		{
			cout<<flag<<endl;
			flag1 = 0;
			continue;
		}
		for(int i = leng -2; i >= 0; i--)
		{
			if(a[i] == 'S' && a[i+1] == 'D')
			{
				for(int j = i; j < leng-1 && a[j+1] != 'S'; j++)
				{
					a[j] = 'D';
					a[j+1] = 'S';
					nowdamage -= sdamage[nums-1];
					sdamage[nums-1] *= 2;
					nowdamage += sdamage[nums-1];
					flag++;
					if(nowdamage >= mindamage)
					{
						cout<<flag<<endl;
						flag1 = 0;
						break;
					}
				}
				if(nowdamage >= mindamage)
					break;
				nums--;
			}	
		}
		if(flag1)
			cout<<"IMPOSSIBLE"<<endl; 
	}
} 
