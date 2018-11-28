#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	int ans = 0;
	while(n != m)
	{
		if(n < m && !(m%2))
			m = m/2;
		else
			m++;
		ans++;
//		cout<<"m : "<<m<<" n :"<<n<<endl;
	}
	cout<<ans<<endl;
}
/*
1 10
2 10
4 10
3 10
6 10
5 10
10 10

1 10 
1 5
1 6
1 3
1 4
1 2
1 1

4 6
8 6
7 6
6 6

4 6
4 3
4 4

4 7
8 7
7 7

4 7
4 8
4 4
*/
