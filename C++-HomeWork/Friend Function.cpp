#include<iostream>
using namespace std;
class Tea;

class Stu
{
		char *name;
		int score;
	public:
		friend void print(Stu student, Tea teacher);
		Stu(char *n, int s)
		{
			name = n;
			score = s; 
		}
};

class Tea
{
		char *name;
		char *pro;
	public:
		friend void print(Stu student, Tea teacher);
		Tea(char *n, char *p)
		{
			name = n;
			pro = p;
		}
};

void print(Stu S, Tea T)
{
	cout<<"student's name:"<<S.name<<"   "<<S.score<<endl;
	cout<<"Teacher's name:"<<T.name<<"   "<<T.pro<<endl;
}

int main()
{
	char stuname[20],teaname[20],teapro[20]; 
	cout<<"������ѧ��������"<<endl; 
	cin>>stuname; 
	cout<<"�������ʦ������"<<endl;
	cin>>teaname;
	cout<<"�������ʦְ�ƣ�"<<endl;  
	cin>>teapro;
	Stu student(stuname,88);
	Tea teacher(teaname,teapro);
	print(student,teacher);
	return 0;
}
