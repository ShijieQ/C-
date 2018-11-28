#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	char art1[1000];
	char let[100][50];
	while (gets(art1) && strcmp(art1, "#"))
	{
		int len = strlen(art1);
		art1[len] = ' ';
		int n = 0, j = 0;
		for (int i = 0; i<len; ++i)
		{
			if (art1[i] != ' ' && art1[i])
			{
				let[n][j++] = art1[i];
				if (art1[i+1] == ' ')
				{
					n++;
					j = 0;
					i++; 
				}
			}
		}
		for(int k = 0; k < n; k++)
 			cout<<let[k]<<endl;
		if (n != 0)
		{
			char *p;
			int cc = 0, judge = 1;
			do
			{
				int j = cc + 1;
				p = let[cc];
				for (int i = cc + 1; i<n; ++i)
					if (strcmp(p, let[i]) != 0)
					{
						strcpy(let[j++], let[i]);
					}
				n = j;
				++cc;
			} while (cc<n - 1);
		}
		cout << n << endl;
	}
	return 0;
}
