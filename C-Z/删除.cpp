#include<iostream>
using namespace std;
void fun(char a[])
{
	int i;
	int num = 0;
	for(i = 0; a[i] != '\0'; i++)
	{
		if(a[i] == '*')
			num++;
		else if(num)
		{
			a[i-num] = a[i];
		}
	}
	a[i-num] = '\0';
}

int main()
{
	char a[100];
	cin>>a;
	fun(a);
	cout<<a<<endl;
	return 0;
}
