#include<iostream>
using namespace std;
class Complex
{
		double real;
		double imag;
	public:
		Complex(double r, double i):real(r),imag(i)
		{ }
		Complex(Complex &a)
		{
			real = a.real;
			imag = a.imag;
		}
		Complex()
		{ }
		~Complex()
		{
			cout<<"destructing!"<<endl;
		}
		void print() const 
		{
			cout<<real;
			if(imag != 0)
			{
				if(imag > 0)
					cout<<"+";
				cout<<imag<<"i";
			}
			cout<<endl;
		}
		friend Complex operator + (const Complex &a, const Complex &b);
		friend ostream& operator << (ostream &s, const Complex &c);
		friend istream& operator >> (istream &s, Complex &c);
};

Complex operator + (const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}

ostream& operator << (ostream &s, const Complex &c)
{
	c.print();
	return s;
}
 
istream& operator >> (istream &s, Complex &c)
{
	s>>c.real;
	s>>c.imag;
	return s;
}

int main()
{
	Complex A1(2.3, 4.6), A2(3.6, 2.8);
	Complex A3,A4,A5,A6;
	A3=A1+A2;
	cout<<A3;
	cin>>A1;
	cout<<A1;
	return 0; 
} 
