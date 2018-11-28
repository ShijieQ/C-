#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char a[9] = {'1','2','3','4','5','6','7','8','9'}; 
	char b[9];
	int b1[9];
	int abc,def,ghi;
	for(abc = 123; abc <= 329; abc++)
	{
		def = abc*2;
		ghi = abc*3;
		sprintf(b,"%d%d%d",abc,def,ghi);
		sort(b,b+9);
		if(!strcmp(a,b))
			printf("%d %d %d\n",abc,def,ghi);
	}
	return 0;
}






for(abc = 123; abc < 329; abc++)
	for(def = 123*2; def < 329*2; def++)
		for(ghi = 123*3; ghi < 329*3; ghi++)
		{
			..
		}
