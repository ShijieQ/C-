#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Caldendar{
protected:
        int m_year;                             
        int m_month;                             
        static long t_day;                  
        int m_day[12];                           
public:
        void setyear(int year);                  
        bool isleapyear();                        
        void getdays();                         
        void print();                           
};
long Caldendar::t_day = 0;

void Caldendar::getdays()                       	//���ÿ���·��ж�����
{
    if(isleapyear() == true)                      //��������꣬��2�·�Ϊ29��
    {
        int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for(int i = 0;i < 12;i++)
        {
            m_day[i] = day[i];
        }
    }
    else                              	//����2�·�Ϊ28��
    {
        int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};  
        for(int i = 0;i < 12;i++)
        {
            m_day[i] = day[i];
        }
    }

}
void Caldendar::setyear(int year)					//�������
{
    m_year = year;
}
bool Caldendar::isleapyear()                 		//�ж��Ƿ�Ϊ����
{
    if((m_year%4 == 0&&m_year%100 != 0)||(m_year%400 == 0))   //�ж�����ķ���
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Caldendar::print()
{
    char *t_month[12] = {"һ�£�Jan��","���£�Feb��","���£�Mar��","���£�Apr��","���£�May��","���£�Jun��","���£�Jul��","���£�Aug��","���£�Sep��","ʮ�£�Oct��","ʮһ�£�Nov��","ʮ���£�Dec��"};         								//�ַ�����洢�����·�����
    char *t_week[7] = {"Sun","Mon","Tue","Wen","Thru","Fri","Sat"};  //�ַ�����洢������������
    long count = 0;                     
    for(int i = 1;i < m_year;i++)       			//�ӹ�Ԫ1�꿪ʼ����������һֱ�ӵ���������Ǹ���ݵ�ǰһ�꣬�����úܼ򵥣�����ȷ���������Ǹ���ݵ�1��1�������ڼ�
    {
        if((i%4 == 0&&i%100 != 0)||(i%400 == 0))	//�����Ԫi�������꣬����������366��
        {
            t_day += 366;
        }
        else{
            t_day += 365;
        }
    }
    count = t_day%7+1;
	cout<<endl<<count<<endl;       					//��������ȡ��7���ɻ������ĸ���1��1�������ڼ���count=1��Ϊ�����죬count=2��Ϊ����һ,����������ο��ſ�
    cout<<"The calendar of the year "<<m_year<<endl;  			//������ǵڼ���
    for(m_month = 0;m_month < 12;m_month++)  	//�ӵ�һ�¿�ʼ������ӡ
    {
        cout<<"---------------------------------"<<endl<<endl;
        cout<<t_month[m_month]<<endl;      	//���д�ӡ�·����ƣ��磺һ�£�Jan��
        for(int m = 0;m < 7;m++)       			//���д�ӡ�������ƣ��磺Sun  Mon  Tue  Wen  Thru  Fri  Sat
        {
            cout<<t_week[m]<<"  ";
        }
        cout<<endl;
        int j = 0;
        for(int k = 0;k < count%7;k++)    		//��������ÿ��1��ǰ��Ҫ�ն��ٿո񣬼�1�������ڼ�
        {
            cout<<setw(3)<<"     ";  			//setw��������������
        }
        for( j = 0;j < m_day[m_month];j++)  		//��ӡÿ�¶�Ӧ����
        {
            count++;                   
            cout<<setw(3)<<j+1<<"  ";
            if(count%7 == 0)          			//�����ģ���count=7ʱ������
            {
                cout<<endl;
            }
        }
        cout<<endl;
    }
}
int main()                              //�˳�����������һ����ݣ���ӡ��������·ݵ�����
{											
    int year = 0;
    double name=0;
    cout<<" Input the year: ";             
    cin>>year;
    cout<<"Input the file name:";
    cin>>name;
    Caldendar p;
    p.setyear(year);							//���ó�Ա����Ϊ�������
    p.getdays();								//���ÿ������
    p.print();									//��ӡ����
    return 0;
}
