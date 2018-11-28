#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Vehicle
{
	protected:
		int MaxSpeed;
		int Weight;
	public:
		Vehicle(int m, int w)
		{
			MaxSpeed = m;//1
			Weight = w;//2
			cout<<"Constructing Vehicle...\n";
		}
		~Vehicle()
		{
			cout<<"Destructing Vehicle...\n";
		}
		void Run()
		{
			cout<<"The vehicle is running!\n";
		}
		void Stop()
		{
			cout<<"Please stop running!\n";
		}
		void show()
		{
			cout<<"It's maxspeed is:"<<MaxSpeed<<endl;
			cout<<"It's weight is:"<<Weight<<endl;
		}
};

class Bicycle: private Vehicle
{
	protected:
		int Height;
	public:
		Bicycle(int m, int w, int h):Vehicle(m,w)//3
		{
			Height = h;//4
			cout<<"Constructing Bicycle...\n";
		}
		~Bicycle()
		{
			cout<<"Destructing Bicycle...\n";
		}
		void show()
		{
			Vehicle::show();//5
			cout<<"It's height is:"<<Height<<endl;//6
		}
};

int main()
{
	Bicycle b(10,20,30);//7
	b.Run();
	b.Stop();
	b.show();
	return 0;
}
