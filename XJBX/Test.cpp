#include<iostream>
//#include<cmath>

using namespace std;
const float pi = 3.14;

class trangle{
	private:
		double a, b, c, z, m;
	public:
		void Input();
		void Perimeter();
		void Area();
		void Output();
};

void trangle::Input(){
	int x, y, z;
	cin>>x>>y>>z;
	a = x;
	b = y;
	c = z;
}

void trangle::Perimeter(){
	z = a+b+c;
}

void trangle::Area(){
	float p = (a+b+c)/2;

	//没有math.h头文件的做法，转自https://blog.csdn.net/qq_26499321/article/details/73724763：
	float x = p*(p - a)*(p - b)*(p - c);
	float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f375a86- (i>>1); 
    x = *(float*)&i; 
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x); 
	m = 1/x;

	/*
	//有math.h头文件的做法：
	m = sqrt(p*(p - a)*(p - b)*(p - c));
	*/
}

void trangle::Output(){
	cout<<"The perimeter is "<<z<<", the area is "<<m<<endl;
}

int main(){
	trangle k;
	k.Input();
	k.Area();
	k.Perimeter();
	k.Output();
	return 0;
}