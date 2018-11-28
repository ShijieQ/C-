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
		Complex operator * (Complex c1)
		{
			Complex c2;
			c2.real = real*c1.real - imag*c1.imag;
			c2.imag = imag*c1.real + real*c1.imag;
			return c2;
		}
		Complex operator / (Complex c1)
		{
			Complex c2;
			c1.imag = -c1.imag;
			c2 = *this * c1;
			c2.real /= c1.real*c1.real + c1.imag*c1.imag;
			c2.imag /= c1.real*c1.real + c1.imag*c1.imag;
			return c2;
		}
		Complex operator ++ (int)
		{
			Complex temp(*this);
			real++;
			imag++;
			return temp;
		}
		void print()
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
		friend Complex operator - (const Complex &a, const Complex &b);
		friend Complex operator ++ (Complex &a);
};

Complex operator + (const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}

Complex operator - (const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real - b.real;
	temp.imag = a.imag - b.imag;
	return temp;
}

Complex operator ++ (Complex &a)
{
	++a.real;
	++a.imag;
	return a;
}

int main()
{
	Complex A1(2.3, 4.6), A2(3.6, 2.8);
	Complex A3,A4,A5,A6;
	A3=A1+A2;
	A4=A1-A2;
	A5=A1*A2;
	A6=A1/A2;
	cout<<"A1=";
	A1.print();
	cout<<endl<<"A2=";
	A2.print();
	cout<<endl<<"A3=A1+A2=";
	A3.print();
	cout<<endl<<"A4=A1-A2=";
	A4.print();
	cout<<endl<<"A5=A1*A2=";
	A5.print();
	cout<<endl<<"A6=A1/A2=";
	A6.print();
	A3=++A1;
	cout<<endl<<"after A3=++A1"<<endl;
	cout<<"A1=";
	A1.print();
	cout<<"A3=";
	A3.print();
	A4=A2++;
	cout<<endl<<"after A4=A2++"<<endl;
	cout<<"A2=";
	A2.print();
	cout<<"A4=";
	A4.print();
	return 0; 
} 
