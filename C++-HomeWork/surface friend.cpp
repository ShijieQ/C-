#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Girl;
class Boy
{
		char *name;
		int age;
	public:
		friend Girl;
		Boy(char *name_,int ag)
		{
			name = new char[20];
			name = name_;
			age = ag;
		}
		void PrintInformation()
		{
			cout<<name<<"  "<<age<<endl;
		}
		void VisitGirl(Girl &obj)
		{
			cout<<obj.name<<endl;
		}
		~Boy()
		{
			cout<<"Destructor called.\n";
		}
	
};

class Girl
{
		char *name;
		int age;
	public:
		Girl(char *name_,int ag)
		{
			name = new char[20];
			name = name_;
			age = ag;
		}
		void PrintInformation()
		{
			cout<<name<<"  "<<age<<endl;
		}
		void VisitBoy(Boy &obj)
		{
			cout<<obj.name<<endl;
		}
		~Girl()
		{
			cout<<"Destructor called.\n";
		}
};
int main()
{
	Boy man("qishijie",18);
	Girl girl("lihaoyu",18);
	girl.VisitBoy(man);
	man.VisitGril(girl);
}
