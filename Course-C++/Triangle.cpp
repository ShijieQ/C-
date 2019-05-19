#include<iostream>
using namespace std;
class Point
{
		double x, y;
	public:
		Point(double x1, double y1):x(x1),y(y1)
		{ }
		Point(Point &temp)
		{
			x = temp.x;
			y = temp.y;
		}
		Point()
		{ }
		double getX()
		{
			return x;
		}
		double getY()
		{
			return y;
		}
		void display()
		{
			cout<<"("<<x<<", "<<y<<")"<<endl;
		} 
};

class Triangle
{
		Point a,b,c;
	public:
		Triangle(Point a1, Point b1, Point c1):a(a1), b(b1), c(c1)
		{ }
		double getline(const Point &a, const Point &b)
		{
			return sqrt((a.getX() - b.getX())*(a.getX() - b.getX()) + (a.getY() - b.getY())*(a.getY() - b.getY()));
		}
		
} 
