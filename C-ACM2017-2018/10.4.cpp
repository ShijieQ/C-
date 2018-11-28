#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int leng,num,a;
		cin>>leng>>num;
		int shorttime1,longtime1;
		int shorttime = 0,longtime = 0;
		int halfleng = leng / 2; 
		for(int i = 1; i <= num; i++)
		{
			scanf("%d",&a);
/*			int c = a - halfleng;
			if(c < 0)
				c = -c;
			if(c == min(shorttime, c))
			{
				shorttime1 = leng - a;
				shorttime = c;
			}
			int d = max(a,leng - a);
			if(d == max(longtime,d))
			{
				longtime1 = d;
				longtime = d;
			}  */
			if(a > halfleng)
			{
				longtime1 = a;
				shorttime1 = leng - a;
			}
			else
			{
				longtime1 = leng - a;
				shorttime1 = a;
			}
			longtime = max(longtime,longtime1);
			shorttime = max(shorttime,shorttime1);
		}
		cout<<shorttime<<" "<<longtime<<endl;
	}
	return 0;
}
