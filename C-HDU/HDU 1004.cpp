#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main()
{
	int n;
	string Color;
	while(cin>>n,n)
	{
		map<string,int> m;
		for(int i = 0; i < n; i++)
		{
			cin>>Color;
			m[Color]++; 
		}
		map<string,int>::iterator it;
		int Max = 0;
		string Max_Color;
		for(it = m.begin(); it != m.end(); it++)
		{
			if(it->second > Max)
			{
				Max = it->second;
				Max_Color = it->first;
			}
		}
		cout<<Max_Color<<endl;
	}
}
