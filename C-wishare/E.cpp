#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int lcs(char a[],char b[],int n,int m)
{
	vector<vector<int> >table(n+1,vector<int>(n+1));
	for(int i= 0; i < n+1; ++i)
	{
		for(int j = 0; j < m+1; ++j)
		{
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(a[i-1] == b[j-1])
				table[i][j] = table[i-1][j-1] + 1;
				else
					table[i][j] = max(table[i-1][j] , table[i][j-1]);
		}
	}
	return table[n][m];
}
int main()
{
	char a[105],b[105];
	int num = 0;
	int n,m;
	cin>>n>>m;
	cin>>a>>b;
	int len = lcs(a,b,n,m);
	cout<<n-len+m-len;			
}
