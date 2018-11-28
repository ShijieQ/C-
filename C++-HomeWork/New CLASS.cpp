#include<cmath>
#include<iomanip>
#include<iostream>
#include<algorithm>
using namespace std;
class Point
{
    private:
        double X, Y;
    public:
        Point(double a, double b)
        {
        	X = a;
        	Y = b;
		}
        Point(Point &p)
        {
        	X = p.X;
        	Y = p.Y;
		}
        double GetX()
        {
        	return X;
		}
        double GetY()
        {
        	return Y;
		}
};
class Line
{
    private:
        Point A, B;
        double length;
    public:
        Line(Point p1, Point p2): A(p1),B(p2)
        {
        	;
		}
        double GetLength()
        {
        	return sqrt((A.GetX()-B.GetX())*(A.GetX()-B.GetX())+(A.GetY()-B.GetY())*(A.GetY()-B.GetY()));
		}
};
int main()
{
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Point a(x1,y1),b(x2,y2);
	Line s(a,b);
	cout<<fixed<<setprecision(2)<<s.GetLength()<<endl;
	return 0;
}
