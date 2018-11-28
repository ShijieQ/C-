#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	char flag[12];
	char flag1[12];
	char mimaji[100][205];
	int ans = 0;
	cin>>flag;//起始输入START 
	while(strcmp(flag,"ENDOFINPUT"))
	{
		char mima[205];
		cin>>mima;//输入密码消息
		cin>>flag1;//输入END 
		for(int i = 0; i < strlen(mima); i++)
		{
			if(mima[i] >= 'A' && mima[i] < 'F')
				mima[i] += 17;
			if(mima[i] >= 'F' && mima[i] <= 'Z')
				mima[i] -= 5;
		}
		strcpy(mimaji[ans], mima);//存储密码 
		ans++; 
		cin>>flag;//输入下一个START
	}
	for(int i = 0; i < ans; i++)
		cout<<mimaji[i]<<endl;
	return 0;
} 
