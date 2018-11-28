#include<iostream>
using namespace std;
class Container
{
	protected:
		double radius;
	public:
		Container(double r):radius(r)
		{ }
		virtual double area() = 0;
		virtual double volume() = 0;
		virtual void print() = 0;
};

class Cube:public Container
{
	public:
		Cube(double r):Container(r)
		{ }
		double area()
		{
			return radius*radius*6;
		}
		double volume()
		{
			return radius*radius*radius;
		}
		void print()
		{
			cout<<"The Cube's area is "<<area()<<endl;
			cout<<"The Cube's volume is "<<volume()<<endl;
		}
}; 

class Sphere:public Container
{
	public:
		Sphere(double r):Container(r)
		{ }
		double area()
		{
			return 4*3.14159*radius*radius;
		}
		double volume()
		{
			return 4*3.14159*radius*radius*radius/3;
		}
		void print()
		{
			cout<<"The Sphere's area is "<<area()<<endl;
			cout<<"The Sphere's volume is "<<volume()<<endl;
		}
};

class Cylinder:public Container
{
	protected:
		double height;
	public:
		Cylinder(double r, double h):Container(r),height(h)
		{ }
		double area()
		{
			return 2*3.14159*radius*radius + 2*3.14159*radius*height;
		}
		double volume()
		{
			return 3.14159*radius*radius*height;
		}
		void print()
		{
			cout<<"The Cylinder's area is "<<area()<<endl;
			cout<<"The Cylinder's volume is "<<volume()<<endl;
		}
};

int main()
{
	Container *p;
	Cube c(5);
	Sphere s(4);
	Cylinder cy(5,4);
	p = &c;
	cout<<p->area()<<endl;
	cout<<p->volume()<<endl;
	p->print();
	p = &s;
	cout<<p->area()<<endl;
	cout<<p->volume()<<endl;
	p->print();
	p = &cy;
	cout<<p->area()<<endl;
	cout<<p->volume()<<endl;
	p->print();
	return 0;
}
