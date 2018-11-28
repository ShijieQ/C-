#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[50005][50005];
int LCS(char *a, char *b)
{
	int i,j;
	for(i=1;i <= strlen(a);i++)
	{
         for(j=1;j <= strlen(b);j++)
		 {
            if(a[i]==b[j])
			 	dp[i][j]=dp[i-1][j-1]+1;
            else 
			 	dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
         }     
	}
	return dp[i-1][j-1];
}
int main()
{
	char a[50005],b[50005];
	scanf("%s",a);
	int j = 1;
	if(strlen(a) <= 2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = strlen(a); i >= 1; i++)
		b[j++] = a[i];
	if(LCS(a,b) == strlen(a) - 2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
