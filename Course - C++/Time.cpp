#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Time
{
		int Hour;
		int Minute;
		int Second;
	public:
		Time(int h,int m,int s)
		{
			Hour = h;
			Minute = m;
			Second = s;
			cout<<"Constructor called.\n";
		}
		Time(const Time &time)
		{
			Hour = time.Hour;
			Minute = time.Minute;
			Second = time.Second;
			cout<<"Copy Constructor called.\n";
		}
		void GetTime()
		{
			cout<<"Please input the time:"<<endl;
			cin>>Hour>>Minute>>Second;
		}
		void PrintTime()
		{
			cout<<setw(2)<<setfill('0')<<Hour<<":"<<setw(2)<<setfill('0')<<Minute<<":"<<setw(2)<<setfill('0')<<Second<<endl;;
		}
		void IncreaceOneSecond()
		{
			int hour = Hour;
			int minute = Minute;
			int second = Second+1;
			if(second >= 60)
			{
				minute++;
				second -= 60;
				if(minute >= 60)
				{
					Hour++;
					minute -= 60;
					if(Hour >= 24)
						Hour -= 24;
				}
			}		 
		}
		~Time()
		{
			cout<<"Destructor called.\n";
		}
		friend int a();
		int a()
		{
			cout<<"123"<<endl;
		} 
}; 

void f(Time t)
{
	t.PrintTime();
}

int main()
{
	Time t1(12,11,56);
	Time t2(t1);
/*	t1.PrintTime();
	t1.GetTime();
	t1.PrintTime(); */ 
	return 0;	
}
