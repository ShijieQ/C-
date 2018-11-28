#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int strstk(char s1[], char s2)
{
	for(int i = 0; i < strlen(s1); i++)
	{
		if(s1[i] == s2)
			return i;
	}
	return 0;
} 
int main()
{
	char a[1005];
	char arr[] = {'0','a', 'e', 'i', 'o', 'u'};
	cin>>a;
	int len = strlen(a);
	if(!strstk(arr, a[len-1]) && a[len-1] != 'n')
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = 0; i < len; i++)
	{
		if(a[i] == 'n')
			continue;
		if(!strstk(arr, a[i]) && !strstk(arr, a[i+1]))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}
