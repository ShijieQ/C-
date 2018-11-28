#include<stdio.h>
#include<string.h>
int main()
{
	int a,i,m=1,n=2,k;
	char st[3][100000];
	while(scanf("%s",&st[0])!=EOF)
	{
		a=0;
		for(i=0;i<strlen(st[0]);)
		{
			if(st[0][i]=='[')
			{
				a=0;
				i++;
				for(;;)
				{
					if(st[0][i]=='['||st[0][i]=='\0')
						{
							strcat(st[m],st[n]);
							m=m^n;
							n=n^m;
							m=m^n;
							a=strlen(st[m]);
							for(k=0;k<a;k++)
								st[m][k]='\0';
							break;							
						}
					if(st[0][i]==']'||st[0][i]=='\0')
						{
							strcat(st[m],st[n]);
							m=m^n;
							n=n^m;
							m=m^n;
							a=strlen(st[m]);
							for(k=0;k<a;k++)
								st[m][k]='\0';
							break;							
						}
						st[m][a]=st[0][i];
						i++;
						a++;
				}
			}
			else if(st[0][i]==']')
			{
				i++;
				a=0;
				for(;;)
				{
					if(st[0][i]==']')
						{
							i++;
							continue;
						}	
					if(st[0][i]=='['||st[0][i]=='\0')
						{
							strcat(st[n],st[m]);
							a=strlen(st[m]);
							for(k=0;k<a;k++)
								st[m][k]='\0';
							break;
						}
						st[m][a]=st[0][i];
						i++;
						a++;
				}
			}
			else if(st[0][i]!='\0')
				for(a=0;;)	
				{
					if(st[0][i]=='['||st[0][i]=='\0')
						break;
					if(st[0][i]==']')
						{
							i++;
							continue;
						}
					st[n][a]=st[0][i];
					i++;
					a++;
				}
		}
		printf("%s\n",st[n]);
		a=strlen(st[n]);
		for(k=0;k<a;k++)
		st[n][k]='\0';
	}
 } 

/*#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[100001];
char beijuf[21][100001];
char beijue[21][100001];
int main()
{
	int i,j,k,first,end;
	while(scanf("%s",&str) != EOF)
	{
		j = k = first = end = 0;
		int n = strlen(str);
		for(i = 0;i < n-1;i++)
		{
			if(str[i] == '[')
			{
				int f = 0;
				for(int a = i;a < n-1;a++)
				{
					
					if(str[a+1] == ']'||'[')
					{
						i = a+1;
						break;
					}
					else 
						beijuf[f][k++] = str[a+1];
				}
				f++;
				first++;
				k = 0;
			}
			if(str[i] == ']')
			{
				int e = 0;
				for(int a = i;a < n-1;a++)
				{
					if(str[a+1] == ']'||'[')
					{
						i = a+1;
						break;
					}
					else 
						beijue[e][k++] = str[a+1];
				}
				e++;
				end++;
				k = 0;
			}
		}
	}
 } */ 
