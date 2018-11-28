#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char str[10005],del[10005],new_[10005];
	gets(str);
	gets(del);
	int sci[256] = {0};
	int num = 0;
	int len1 = strlen(str);
	int len2 = strlen(del);
	for(int i = 0; i < len2; i++)
		sci[del[i]] = 1;
	for(int i = 0; i < len1; i++)
	{
		if(!sci[str[i]])
			new_[num++] = str[i];	
	}
	for(int i = 0; i < num; i++)
		cout<<new_[i];
	return 0;
} 
