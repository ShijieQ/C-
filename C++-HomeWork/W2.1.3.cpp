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
			MaxSpeed = m;
			Weight = w;
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

class Bicycle: virtual public Vehicle
{
	protected:
		int Height;
	public:
		Bicycle(int m, int w, int h):Vehicle(m,w)
		{
			Height = h;
			cout<<"Constructing Bicycle...\n";
		}
		~Bicycle()
		{
			cout<<"Destructing Bicycle...\n";
		}
		void show()
		{
			Vehicle::show();
			cout<<"It's height is:"<<Height<<endl;
		}
};

class Car: virtual public Vehicle
{
	protected:
		int SeatNum;
	public:
		Car(int m, int w, int s):Vehicle(m, w)//8
		{
			SeatNum = s;//9
			cout<<"Constructing Car...\n";
		}
		~Car()
		{
			cout<<"Destructing Car...\n";
		}
		void show()
		{
			Vehicle::show();//10
			cout<<"It's seatnum is:"<<SeatNum<<endl;//11
		}
};

class MotorCycle: public Bicycle, public Car
{
	public:
		MotorCycle(int m, int w, int h, int s): Bicycle(m,w,h), Car(m,w,s)//14
		{
			cout<<"Constructing MotorCycle...\n";
		}
		~MotorCycle()
		{
			cout<<"Destructing MotorCycle...\n";
		}
		void show()
		{
			cout<< "It's maxspeed is:" << MaxSpeed <<endl;
			cout<< "It's weight is:" << Weight <<endl;
			cout<< "It's height is:" << Height <<endl;
			cout<< "It's seatnum is:" << SeatNum <<endl;
		}
};

int main()
{
	MotorCycle mc(10,20,30,7);//15
	mc.Run();
	mc.Stop();
	mc.show();
	return 0;
}
/*
	MotorCycle(int m, int w, int h, int s): Bicycle(m,w,h), Car(m,w,s), Vehicle(m, w)  //16
	*/
