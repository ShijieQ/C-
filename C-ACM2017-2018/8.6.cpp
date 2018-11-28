#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		double a,b1,c;
		a = ((y1-y2)/(x1-x2)-(y2-y3)/(x2-x3))/((x1*x1-x2*x2)/(x1-x2)-(x2*x2-x3*x3)/(x2-x3));
		b1 = -1*a*(x2*x2-x3*x3)/(x2-x3)+(y2-y3)/(x2-x3);
		c = y1-b1*x1-a*x1*x1;
		double k,b2;
		k = (y2 -y3) / (x2 - x3);
		b2 = y2 - k*x2;
		double area = 0;
		area = a*(x3*x3*x3 - x2*x2*x2)/3 + (b1-k)*(x3*x3 - x2*x2)/2 + (c-b2)*(x3 - x2);
		printf("%.2f\n",area);
	}
	return 0;
}
