#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int t=100;
	while(--t)
        {
		system("rand.exe > data.txt");
		system("ac.exe < data.txt > ac.txt");
		system("my.exe < data.txt > my.txt");
		if(system("fc ac.txt my.txt"))
			break;
	}  
	if(t==0)
		cout<<"no error"<<endl;
	else
		cout<<"error"<<endl;
	system("pause");
	return 0;
	
} 
