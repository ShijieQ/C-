#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;
int main()
{
	set<string> ss;
	char s[1005];
	while(gets(s) && strcmp(s, "#"))
	{
		char temp[1005];
		memset(temp, 0, sizeof(temp));
		int len = strlen(s);
		s[len] = ' ';
		for(int i = 0, j = 0; i <= len; i++)
		{
			if(s[i] != ' ')
				temp[j++] = s[i];
			else
			{
				temp[j] = '\0';
				if(strlen(temp))
					ss.insert(temp);
				memset(temp, 0, sizeof(temp));
				j = 0;
			}
		}
		cout<<ss.size()<<endl;
		ss.clear();
	}
} 
