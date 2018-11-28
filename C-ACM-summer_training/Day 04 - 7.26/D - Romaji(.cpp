#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i = 0; i < s.size(); i++)
	{
		if(!strchr("aeioun", s[i]))
		{
			if(i+1 >= s.size() || !strchr("aeiou", s[i+1]))
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
} 
