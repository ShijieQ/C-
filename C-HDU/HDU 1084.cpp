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
		stu s[maxn];//�洢ѧ����Ϣ�Ľṹ�� 
		stu s1[maxn];//��Ϊ�ṹ�徭��������ԭ�ȵ�˳��ͬ�����Զ���һ��s1���洢ԭʼ���� 
		//int grade[maxn];
		int num[6] = {0,0,0,0,0,0};
		for(int i = 0; i < T; i++)
		{
			cin>>s[i].flag>>s[i].time;
			num[s[i].flag]++;
			s1[i] = s[i];//����ԭʼ���� 
		}
		sort(s, s+T, cmp1);//������ 
		int ans = 0;
		

		for(int i = 5; i >= 0; i--)
		{
			sort(s+ans,s+ans+num[i],cmp);
			int j;
			/*
				�Դ�����Ŀ��ͬ��ǰһ���ͬѧ�ͺ�һ���ͬѧд��ɼ�
				*/ 
			for(j = ans; j < ans+num[i]/2; j++)
				s[j].grade = point[i][1];
			for( ; j < ans+num[i]; j++)
				s[j].grade = point[i][0];
			ans += num[i];
		}
		/*
			ͨ������ԭʼ��Ϣ�����������������ԭʼ���ݶ�Ӧ�ķ�����
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
