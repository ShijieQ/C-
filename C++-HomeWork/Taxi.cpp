#include<iostream>
#include<algorithm>
using namespace std;
class Station
{
	protected:
		char *from;
		char *to;
	public:
		Station(char *f, char *t):from(f),to(t)
		{ }
		void disp()
		{
			cout<<from<<" "<<to<<" ";
		}
};

class Mile
{
	protected:
		double mile;
	public:
		Mile(double m):mile(m)
		{ }
		void disp()
		{
			cout<<mile<<" ";
		}
};

class Price:public Station, public Mile
{
	private:
		double price;
	public:
		Price(char *f, char *t, double m):Station(f, t), Mile(m)
		{
			if(mile <= 3)
				price = 8;
			else if((int)((mile-3)*2) == (mile-3)*2)
			{
				price = int((mile-3)*2)*0.7 + 8;
			}
			else
				price = (int((mile-3)*2)+1)*0.7 + 8;
		}
		void disp()
		{
			Station::disp();
			Mile::disp();
			cout<<price<<endl;
		}
};

int main()
{
	char f[20], t[20];
	double m;
	cin>>f>>t>>m;
	Price p(f,t,m);
	p.disp();
	return 0;
}

