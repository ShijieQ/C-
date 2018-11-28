#include<iostream>
using namespace std;
class Base
{
	public:
		int i;
		Base (int x): i(x)
		{ }
		void show()
		{
			cout << "i in Base is: " << i << endl;
		}
};

class Derived: public Base
{
	public:
		Derived (int x): Base(x)
		{ }
		void show()
		{
			cout << "i in Derived is: " << i << endl;
		}
};

int main()
{
	Base b1(3);//1
	cout << "������� b1.show(): \n";
	b1.show();
	Derived d1(4);//2
	b1.Base::i = d1.Derived::i;//3
	cout << "����b1=d1, b1.show(): \n";
	b1.show();
	cout << "��������� d1.show(): \n";
	d1.show();
	Base &b2 = d1;//4
	cout << "����b2=d1, b2.show(): \n";
	b2.show();
	Base *b3 = &d1;//5
	cout << "����ָ��b3=&d1, b3->show(): \n";
	b3->show();
	Derived *d4 = &d1;//6
	Base *b4 = d4;
	cout << "����ָ��b4=d4, b4->show(): \n";
	b4->show();
	cout << "������ָ��d4, d4->show(): \n";
	d4->show();
	delete d4;
	Derived d5=b1;
	Derived &d6=b1;
	Derived *d7=&b1;
    d7=b3;
	return 0; 
}
