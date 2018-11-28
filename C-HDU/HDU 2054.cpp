#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void del_0(char a[])
{
	char temp[100000];
	int flag = 0;
	int len = strlen(a);
	if(len == 1)
		return;
	for(int i = 0; i < len; i++)
		if(a[i] == '.')
		{
			flag = 1;
			break;
		}
	int begin_ = 0, end_ = len-1;
	if(flag)
	{
		for(int i = 0; a[i] == '0' && a[i] != '.' && i < len; i++)
			begin_ = i+1;
		if(begin_ == len)	
			strcpy(a, "0");
		if(a[begin_] == '.') begin_--;
		for(int i = len-1; a[i] == '0'&& a[i] != '.' && i >= 0; i--)
			end_ = i-1;
		if(a[end_] == '.') end_--;
		int j = 0;
		for(int i = begin_; i <= end_; i++)
			temp[j++] = a[i];
		temp[j] = '\0';
		strcpy(a, temp);
	}
	else
	{
		for(int i = 0; a[i] == '0' && i < len; i++)
			begin_ = i+1;
		if(begin_ == len)
			strcpy(a, "0");
		int j = 0;
		for(int i = begin_; i < len; i++)
			temp[j++] = a[i];
		temp[j] = '\0';
		strcpy(a, temp);
	}
}
int main()
{
    char a[100000],b[100000];
    while(scanf("%s %s",a,b)!=EOF)
    {
    	del_0(a);
    	del_0(b);
    //	cout<<a<<endl;
    //	cout<<b<<endl;
        if(!strcmp(a, b))
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;
    }
    return 0;
}
