#include<iostream>
#include<algorithm>
using namespace std;
char s[][10] = {"One", "Two", "Three", "Four", "Five", "Six"};
int ans = 0;
class Date
{
		int year;
		int month;
		int day;
	public:
		Date(int y=2000, int m=1, int d=1):year(y), month(m), day(d)
		{ }
		void dateset(int y, int m, int d)
		{
			year = y;
			month = m;
			day = d;
		}
		int Getyear()
		{
			return year;
		}
		int Getmonth()
		{
			return month;
		}
		int Getday()
		{
			return day;
		}
	
};

class Product
{
    	char *name;
    	double price;
    	Date deptime;
    	char *factory;
    	bool easy_break;
    	Date valtime; 
       	char *color;
       	double unname1;
       	double unname2;
	public:
       	Product(char *n, double p = 0, int y1 = 2000, int m1 = 1, int d1 = 1, char *f = "unnamed", bool e = 0):deptime(y1, m1, d1)
		{
			name = n;
			price = p;
			factory = f;
			easy_break = e;
			cout<<"Constrcting "<<s[ans++]<<"...."<<endl;
		}
		void SetProduct(char *n, double p, int y, int m, int d, char *f, bool e, int y1, int m1, int d1, char *c, double u)
		{
			name = n;
			price = p;
			deptime.dateset(y, m, d);
			factory = f;
			easy_break = e;
			valtime.dateset(y1, m1, d1);
			color = c;
		}
    	void output()
		{
			cout<<name<<" "<<price<<endl;
       		cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
       		cout<<factory<<" "<<easy_break<<endl;
       		cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
		} 
};
 
int main()
{
    char s[10];
    cin>>s;
    Product p1("car");
    Product p2("glass",3.00);
    Product p3("pen",5.00,2009,3,14);
    p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red",1.5);
    p1.output();
    p2.output();
    p3.output();
    return 0;
}
