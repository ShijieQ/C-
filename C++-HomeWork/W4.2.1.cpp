#include<iostream>
#include<fstream>
using namespace std;
void ReadFile(char *s)
{
	char ch;
	ifstream in(s);
	if(!in)
	{
		cout<<"Error!"<<endl;
		return ;
	}
	while(in.get(ch))
	{
		cout<<ch;
	}
	in.close();
}

void Change(char *s1, char *s2)
{
	ifstream in(s1);
	ofstream out(s2);
	char ch;
	while(in.get(ch))
	{
		if(ch >= 97 && ch <= 122)
			out.put(ch-32);
		else
			out.put(ch);
	}
	in.close();
	out.close();
}

int main()
{
	ReadFile("ff.txt");
	Change("ff.txt", "ff2.txt");
	ReadFile("ff2.txt");
	return 0;
}
