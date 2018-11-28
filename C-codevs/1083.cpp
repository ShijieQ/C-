#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int num = 1, sum = 0;
	for(;;)
	{	
		if(sum >= a)
			break;
		sum += num;
		num++;
	}
	num--;
	sum -= num;
/*	cout<<"num = "<<num<<endl;
	cout<<"sum = "<<sum<<endl;*/
	if(num%2 == 1)
		cout<<num - a + sum + 1<<"/"<<a - sum<<endl;
	else
		cout<<a - sum<<"/"<<num - a + sum + 1<<endl;
	return 0;
} 
