#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Caldendar
{
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

void Caldendar::getdays()                       	//获得每个月份有多少天
{
    if(isleapyear() == true)                      //如果是闰年，则2月份为29天
    {
        int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for(int i = 0;i < 12;i++)
        {
            m_day[i] = day[i];
        }
    }
    else                              	//否，则2月份为28天
    {
        int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};  
        for(int i = 0;i < 12;i++)
        {
            m_day[i] = day[i];
        }
    }

}
void Caldendar::setyear(int year)					//设置年份
{
    m_year = year;
}

bool Caldendar::isleapyear()                 		//判断是否为闰年
{
    if((m_year%4 == 0&&m_year%100 != 0)||(m_year%400 == 0))   //判断闰年的方法
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
    char *t_month[12] = {"一月（Jan）","二月（Feb）","三月（Mar）","四月（Apr）","五月（May）","六月（Jun）","七月（Jul）","八月（Aug）","九月（Sep）","十月（Oct）","十一月（Nov）","十二月（Dec）"};         								//字符数组存储各个月份名称
    char *t_week[7] = {"Sun","Mon","Tue","Wen","Thru","Fri","Sat"};  //字符数组存储各个星期名称
    long count[12];                     
    for(int i = 1;i < m_year;i++)       			//从公元1年开始加总天数，一直加到你输入的那个年份的前一年，其作用很简单，就是确定你输入那个年份的1月1号是星期几
    {
        if((i%4 == 0&&i%100 != 0)||(i%400 == 0))	//如果公元i年是闰年，则总天数加366天
        {
            t_day += 366;
        }
        else{
            t_day += 365;
        }
    }
    count[0] = t_day%7+1;    					//用总天数取余7，可获得输入的该年1月1号是星期几，count=1则为星期天，count=2则为星期一,可与程序结果参考着看
    for(int i = 0; i < 11; i++)
    	count[i+1] = m_day[i] + count[i];
/*    for(int i = 0; i < 12; i++)
    	cout<<count[i]<<endl;			*/		//每个月1号对应的全年中的天数 
	cout<<"The calendar of the year "<<m_year<<endl;  			//输出这是第几年
    for(m_month = 0;m_month < 12;m_month += 2)  	//从第一月开始遍历打印
    {
    	int flag = 1;						//确定输入是否为第一行 
        cout<<"---------------------------------           ---------------------------------"<<endl<<endl;
//      cout<<t_month[m_month]<<"                           "<<t_month[m_month+1]<<endl;
		cout<<t_month[m_month]<<"                  		    "<<t_month[m_month+1]<<endl;      	//这行打印月份名称，如：一月（Jan）
		
		
		for(int m = 0;m < 7;m++)       			//这行打印各周名称，如：Sun  Mon  Tue  Wen  Thru  Fri  Sat
        {
            cout<<t_week[m]<<"  ";
        }
		cout<<"        ";
        for(int m = 0;m < 7;m++)       			//这行打印各周名称，如：Sun  Mon  Tue  Wen  Thru  Fri  Sat
        {
            cout<<t_week[m]<<"  ";
        }
        cout<<endl;
        
        for(int k = 0;k < count[m_month]%7;k++)    		//用来控制每月1号前需要空多少空格，即1号是星期几
        {
            cout<<setw(3)<<"     ";  			//setw用来控制输出间隔
        }
        int j[2];
        j[0] = 0;
        j[1] = 0;
        for( ;j[0] < m_day[m_month];j[0]++)  		//打印每月对应天数
        {
            count[m_month]++;                   
            cout<<setw(3)<<j[0]+1<<"  ";
            if(count[m_month]%7 == 0)          			//接上文，当count=7时，换行
            {
                cout<<"         ";
                if(flag)
                {
                	for(int k = 0;k < count[m_month+1]%7;k++)    		//用来控制每月1号前需要空多少空格，即1号是星期几
        			{
            			cout<<setw(3)<<"     ";  			//setw用来控制输出间隔
        			}
        			flag = 0;
				}
				for(  ;j[1] < m_day[m_month+1];j[1]++)  		//打印每月对应天数
        		{
            		count[m_month+1]++;                   
            		cout<<setw(3)<<j[1]+1<<"  ";
            		if(count[m_month+1]%7 == 0)          			//接上文，当count=7时，换行
            		{
                		cout<<endl;
                		j[1]++;
                		break;
            		}
            	}
            	if(j[1] == m_day[m_month+1])
            		cout<<endl; 
        	}
        }
//        cout<<endl<<count[m_month]<<endl<<count[m_month+1]<<endl;
		//当同一行的月份日历中右端的行数多于左端时，右端剩余部分不会被输出，特判一下 
        if(j[1] < m_day[m_month+1])
        {
        	for(int k = 0;k < 6 - count[m_month]%7;k++)    		//用来控制每月1号前需要空多少空格，即1号是星期几
        	{
            	cout<<setw(3)<<"     ";  			//setw用来控制输出间隔
        	}
        	cout<<"              ";
        	for(  ;j[1] < m_day[m_month+1];j[1]++)  		//打印每月对应天数
        	{
            	count[m_month+1]++;                   
            	cout<<setw(3)<<j[1]+1<<"  ";
            	if(count[m_month+1]%7 == 0)          			//接上文，当count=7时，换行
            	{
                	cout<<endl<<"                                            ";
            	}
            }
		}
        cout<<endl;
    }
        
}

int main()                              //此程序功能是输入一个年份，打印出该年各月份的日历
{											
    int year = 0;
    double name=0;
    cout<<" Input the year: ";             
    cin>>year;
    cout<<"Input the file name:";
    cin>>name;
    Caldendar p;
    p.setyear(year);							//设置成员变量为输入年份
    p.getdays();								//获得每月天数
    p.print();									//打印日历
    return 0;
}

