#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char a[1005] = {0},b[1005] = {0};
	int new_a[1005] = {0},new_b[1005] = {0};
	int n,Case = 0,flag = 1;
	cin>>n;
	while(n--)
	{
		int c[1005] = {0};
		int k;
		if(flag) flag = 0;
		else cout<<endl;
		cin>>a>>b;
		int a_begin,b_begin;
		int al = strlen(a);
		int bl = strlen(b);
		for(int i = 0; i < al; i++)
			if( a[i]!= '0' && a[i] != NULL)
			{
				a_begin = i;
				break;
			}
			else if( a[i] == '0' && i == al - 1)
			{
				a_begin = 0;
				al = 1;
				break;
			}
		for(int i = 0; i < bl; i++)
			if( b[i] != '0' && b[i] != NULL)
			{
				b_begin = i;
				break;
			}
			else if( b[i] == '0' && i == bl - 1)
			{
				b_begin = 0;
				bl = 1;
				break;
			}
		for(int i = al - 1,j = 0; i >= a_begin; i--)
			new_a[j++] = a[i] - '0';
		for(int i = bl - 1,j = 0; i >= b_begin; i--)
			new_b[j++] = b[i] - '0';
		for(int i = 0; i <= max(al - a_begin,bl - b_begin); i++)
		{
			c[i] = new_a[i] + new_b[i] +c[i];
			c[i+1] = c[i] / 10;
			c[i] = c[i] % 10;
		}
		cout<<"Case "<<++Case<<":"<<endl;
		for(int i = al - a_begin - 1; i >= 0; i--)
			cout<<new_a[i];
		cout<<" + ";
		for(int i = bl - b_begin - 1; i >= 0; i--)
			cout<<new_b[i];
		cout<<" = ";
		k = max(al - a_begin, bl - b_begin);
		if(c[k] != 0)
		{
			for(int i = k; i >= 0; i--)
				cout<<c[i];
			cout<<endl;
		}
		else
		{
			for(int i = k-1; i >= 0; i--)
				cout<<c[i];
			cout<<endl;
		}
		for(int i = 0; i <= k; i++)
			new_a[i] = new_b[i] = 0;
		
	}
	return 0;
}
