#include<iostream>
using namespace std;
template <class T>
class Complex
{
		T real;
		T imag;
	public:
		Complex(T r, T i):real(r),imag(i)
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
		template <class Q>
		friend Complex<Q> operator + (const Complex<Q> &a, const Complex<Q> &b);
		template <class Q>
		friend ostream& operator << (ostream &s, const Complex<Q> &c);
		template <class Q>
		friend istream& operator >> (istream &s, Complex<Q> &c);
};

template <class T>
Complex<T> operator + (const Complex<T> &a, const Complex<T> &b)
{
	Complex<T> temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}

template <class T>
ostream& operator << (ostream &s, const Complex<T> &c)
{
	c.print();
	return s;
}

template <class T>
istream& operator >> (istream &s, Complex<T> &c)
{
	s>>c.real;
	s>>c.imag;
	return s;
}

int main()
{
	Complex<double> A1(2.3, 4.6), A2(3.6, 2.8);
	Complex<double> A3,A4,A5,A6;
	A3=A1+A2;
	cout<<A3;
	cin>>A1;
	cout<<A1;
	return 0; 
} 
