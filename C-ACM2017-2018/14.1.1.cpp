#include<iostream>
#include<cstring>
using namespace std;
char str[500005];
int num[300000];
int main()
{
	cin>>str;
	int l=strlen(str);
	int i,j=0;
	for(i=0;i<l/2;i++)
		if(str[i]!=str[l-1-i])
		{
			num[j]=i;
			j++;
		}
	if(j!=0&&j!=2&&j!=1)
		cout<<"NO"<<endl;
	else if(j==0)
		cout<<"YES"<<endl;
	else if(j==2)
	{
		if((str[num[0]]==str[l-1-num[1]]&&str[num[1]]==str[l-1-num[0]])||(str[num[0]]==str[num[1]]&&str[l-1-num[1]]==str[l-1-num[0]]))
			cout<<"YES"<<endl;
	}
	else if((l%2)==1&&j==1&&(str[l/2]==str[num[0]]||str[l/2]==str[l-1-num[0]]))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

