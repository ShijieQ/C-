#include<stdio.h>
int main()
{
	int a,b;
	char answer;
	printf("Do u love me?Answer yes(y) or no(n):");
	do
	{	
	    scanf("%c",&answer);
	    if(answer=='n')
		   {
		   printf("DAWN!try again:");
	       }
	}while(answer!='y');
	printf("\a\a\a\a\a\a\a\aARE U KIDDING ME!!!!!!!!!!!!??????????????\n");
	printf("I love You too!(LIE)");
	return 0;
 } 
