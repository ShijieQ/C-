//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
#include<stdlib.h>
#include<set>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数
    //freopen("data.in","w",stdout);
    //以下写你自己的数据生成代��
    	set<pair<int,int> > s;
	//	for(int x1=1;x1<=3;x1++)
	//		for(int y1=4;y1<=6;y1++)
	//   	   		for(int x2=8;x2<=10;x2++)
	 //  	   			for(int y2=4;y2<=6;y2++)
	 //  	   			{
	   	   				int x1=random(1,10000)%3+1;
	   	   				int y1=random(1,10000)%3+4;
	   	   				int x2=random(1,10000)%3+8;
	   	   				int y2=random(1,10000)%3+4;
	   	   				printf("7 %d %d\n",x1,y1);
    					srand(seed);
	   	   				printf("G %d %d\n",x2,y2);
	   	   				s.clear();
	   	   				pair<int,int> p;
	   	   				p.first=x1;
	   	   				p.second=y1;
	   	   				s.insert(p);
	   	   				p.first=x2;
	   	   				p.second=y2;
	   	   				s.insert(p);
	   	   				for(int i=0;i<6;i++)
	   	   				{
	   	   					int a=random(1,10000)%3+1;
	   	   					if(a==1)
	   	   						printf("C");
	   	   					else if(a==2)
	   	   						printf("H");
	   	   					else if(a==3) 
	   	   						printf("R");
		   	   				p.first=random(1,10000)%10+1;
		   	   				p.second=random(1,10000)%9+1;
	   	   					while(s.find(p)!=s.end())
	   	   					{
		   	   					p.first=random(1,10000)%10+1;
		   	   					p.second=random(1,10000)%9+1;
		   	   				}
	   	   					s.insert(p);
	   	   					printf(" %d %d\n",p.first,p.second);
						}
					//}
		printf("0 0 0\n");

}
