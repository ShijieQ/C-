#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
char a[51][51];
int dfs(int i,int j,int x,int y,int num)
{
	num++;
	if(i < 0|| j < 0|| i >= x|| j >= y)
		return num;
	a[i][j] = '#';
	for(int m = i-1; m <= i+1; m++)
		for(int n = j-1; n <= j+1; n++)
			if(m >=0 && n >=0 && m < x && n < y && a[m][n] == '*')
				dfs(m,n,x,y,num);
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int x,y,num = 0;
		cin>>x>>y;
		for(int i = 0; i < x; i++)
			for(int j = 0; j < y; j++)
				cin>>a[x][y];
		for(int i = 0; i < x; i++)
			for(int j = 0; j < y; j++)
				if(a[i][j] == '*')
					dfs(i,j,x,y,num);
		cout<<num<<endl;
		num = 0;
	}
}
