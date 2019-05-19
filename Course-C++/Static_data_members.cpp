#include<iostream>
#include<cstring>
using namespace std;

class Student
{
		int age;
		char *name;
	public:
		static int count;
		Student(int m,char *n)
		{
			age = m;
			name = n;
			count++;
		}
		Student()
		{
			age = 0;
			name = new char[20];
			strcpy(name,"unnamed");
			count++;
		}
		~Student()
		{
			count--;
		}
		void Print() const
		{
			cout<<"count="<<count<<endl;
			cout<<name<<"  "<<age<<endl;
		}
};
int Student::count = 0;

int main()
{
	cout<<"count="<<Student::count<<endl;
    char stuname[20]="ZhangHong";
    Student s1,*p=new Student(23,stuname);
    s1.Print();
    p->Print();
    delete p;
    s1.Print();
    Student Stu[4];
    cout<<"count="<<Student::count<<endl;
    return 0;
}
