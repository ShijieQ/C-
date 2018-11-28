#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#define maxn 105
using namespace std;

typedef struct stu
{
	int flag;
	char time[15];
	int grade;
}stu;

bool cmp(struct stu a, struct stu b)
{
	if(strcmp(a.time, b.time) == -1)
		return true;
	else return false;
}

bool cmp1(struct stu a, struct stu b)
{
	if(a.flag > b.flag)
		return true;
	else return false;
}
int main()
{
	int T;
	int point[6][2] = {50,50,60,65,70,75,80,85,90,95,100,100};
	while(scanf("%d", &T) != EOF && T != -1)
	{
		time_t start,ending;
		start = time(NULL); 
		stu s[maxn];//存储学生信息的结构体 
		stu s1[maxn];//因为结构体经过排序与原先的顺序不同，所以定义一个s1来存储原始数据 
		//int grade[maxn];
		int num[6] = {0,0,0,0,0,0};
		for(int i = 0; i < T; i++)
		{
			cin>>s[i].flag>>s[i].time;
			num[s[i].flag]++;
			s1[i] = s[i];//保存原始数据 
		}
		sort(s, s+T, cmp1);//排序函数 
		int ans = 0;
		

		for(int i = 5; i >= 0; i--)
		{
			sort(s+ans,s+ans+num[i],cmp);
			int j;
			/*
				对答题数目相同的前一半的同学和后一半的同学写入成绩
				*/ 
			for(j = ans; j < ans+num[i]/2; j++)
				s[j].grade = point[i][1];
			for( ; j < ans+num[i]; j++)
				s[j].grade = point[i][0];
			ans += num[i];
		}
		/*
			通过查找原始信息和排序后的排名，输出原始数据对应的分数。
			*/ 
		for(int i = 0; i < T; i++)
		{
			for(int j = 0; j < T; j++)
			{
				if(!strcmp(s1[i].time, s[j].time) && s1[i].flag == s[j].flag)
				{
					cout<<s[j].grade<<endl;
					break;
				}
			}
		}  
		cout<<endl;
		ending = time(NULL);
		cout<<"The time is "<<difftime(ending, start)<<endl<<endl;
	}
}
