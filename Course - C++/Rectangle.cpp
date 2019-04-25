#include<iostream>
#include<algorithm>
using namespace std;
class square
{
	protected:
		float length;
		float width;
	public:
		square(float len,float wid)
		{
			length = len;
			width = wid;
		}
		float area()
		{
			return length*width;
		}
		void disp()
		{
			cout<<area()<<" ";
		}
};
class Rectangle:public square
{
	private:
		float height;
	public:
		Rectangle(float len,float wid,float hei):square(len,wid)
		{
			height = hei;
		}
		float calv()
		{
			return length*width*height;
		}
		void disp()
		{
			cout<<calv()<<endl;
		}
};
int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	Rectangle s(a,b,c);
	s.square::disp();
	s.Rectangle::disp();
	return 0;
} 
