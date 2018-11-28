#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool cmp(string a, string b)
{
	return a.size() < b.size();
}
int main()
{
	int n;
	cin>>n;
	string a[105];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	sort(a, a+n, cmp);
	for(int i = 0; i < n-1; i++)
	{
		if(!strstr(a[i+1].c_str(), a[i].c_str()))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"; 
	for(int i = 0; i < n; i++)
		cout<<endl<<a[i];
}
