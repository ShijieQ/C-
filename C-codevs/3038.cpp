#include<iostream>
#include<algorithm>
using namespace std;
int ans = 0;
int cp(int n)
{
	if(n == 1)
		return ans;
	if(n%2)
		n = 3*n + 1;
	else
		n = n / 2;
	ans++;
	return cp(n);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cout<<cp(n)<<endl;
		ans = 0;
	}
	return 0;
} 
