#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char n[100];
	int m,i,sum=0;
	scanf("%s%d",n,&m);
	for(i = strlen(n)- 1; i>=0; i--)
	{
		if(n[i]>='0'&&n[i]<='9') 
			sum+=(n[i]-('1'-1))*pow(m,strlen(n)-1-i);
		else 
			sum+=(n[i]-('A'-10))*pow(m,strlen(n)-1-i);
	} 
	printf("%d",sum);
	return 0;
}
