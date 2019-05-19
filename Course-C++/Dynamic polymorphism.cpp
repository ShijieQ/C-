#include<iostream>
#include<algorithm>
#define pi 3.1415
using namespace std;
class shape
{
	public:
		virtual double volume()=0;
}; 

class cylinder:public shape
{
	private:
		double r;
		double h;
	public:
		cylinder(double r1, double h1):r(r1),h(h1)
		{ }
		double volume()
		{
			return pi*r*r*h;
		}
};

class sphere:public shape
{
	private:
		double r;
	public:
		sphere(double r1):r(r1)
		{ }
		double volume()
		{
			return 4*pi*r*r*r/3;
		}
};

int main() 
{
	shape *p;
	double  r,h;
	cout<<"input r & h£º"<<endl;
	cin>>r>>h;
	cylinder cy(r,h);
	sphere sp(r);
	p=&cy;
	cout<<p-> volume()<<endl;    		
	p=&sp;
	cout<<p-> volume()<<endl; 
	return 0;
}
