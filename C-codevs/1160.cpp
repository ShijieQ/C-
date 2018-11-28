#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int s[105][105];
int main()
{
	int a,num;
	int x,y;
	cin>>a;
	memset(s,0,sizeof(s));
	s[x = a][y = a] = a*a;
	num = a*a;
	while(num > 1)
	{
		while(y - 1 > 0 && !s[x][y-1]) s[x][--y] = --num;
		while(x - 1 > 0 && !s[x-1][y]) s[--x][y] = --num;
		while(y + 1 <= a && !s[x][y+1]) s[x][++y] = --num;
		while(x + 1 <= a && !s[x+1][y]) s[++x][y] = --num;
	}
	int ans = 0;
	for(int i = 1; i <= a; i++)
	{
		for(int j = 1; j < a; j++)
		{
			cout<<s[i][j]<<" ";
			if(i == j || i+j == a+1)
				ans += s[i][j];
		}
		cout<<s[i][a]<<endl;
	}
	ans += s[1][a];
	ans += s[a][a];
	cout<<ans<<endl;
}
