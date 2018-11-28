/*´òÓ¡ÏÂ±í 
   ***
  *****
 *******
*********  
*/
#include <stdio.h>
int main()
{
	int i,a,b;
	char m,n;
	m='*',n=32;
	for(i=1;i<=4;i++)
	{
	   for(a=1;a<=4-i;a++)
	   {
	      printf("%c",n);
       }
	   for(b=1;b<=2*i+1;b++)
	   {
	      printf("%c",m);
       }
	   	printf("\n");
	}
	return 0;
 } 
