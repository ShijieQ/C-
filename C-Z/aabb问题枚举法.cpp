#include<stdio.h>
int main()
{
	for(int x = 1; ;x++)
	{
		int n = x * x;
		if(n < 1000) continue;
		if(n > 9999) break;
		int i = n / 100;
		int j = n % 100;
		if(i / 10 == i % 10 && j / 10 == j % 10)  printf("%d	",n);
	}
	return 0; 
 } 
