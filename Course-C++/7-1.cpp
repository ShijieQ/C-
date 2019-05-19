#include<iostream>
#include<algorithm>
using namespace std;
template <class T>
void swag(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	double a, b;
	cin>>a>>b;
	swag(a, b);
	cout<<a<<" "<<b<<endl;
	return 0;
}

