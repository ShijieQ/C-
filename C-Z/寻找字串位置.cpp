/*#include<stdio.h>
int main()
{
	char str1[100],str2[100];
	int i,j;
	scanf("%s",&str1);
	scanf("%s",&str2);
	for(i = 0;i < 100;i++)
	{
		for(j = 0;j < 100;j++)
		{
			if(str1[i] == str2[j]&&str1[i+1] == str2[j+1]&&str1[i+2] == str2[j+2])
			  break;
		}
		if(str1[i] == str2[j]&&str1[i+1] == str2[j+1]&&str1[i+2] == str2[j+2])
			  break;
		
	}
	printf("%d",i+1);  
	return 0;
}
*/

 #include<stdio.h>
int main()
{
	char str[100],str2[100];
	int i,j;
	for(i = 0;i < 100;i++)
	{
		str[i] = getchar ();
		if(str[i] == ' ')
		 { break; }
	}
	for(j = 0;j < 100;j++)
	{
		str2[j] = getchar ();
		for(i = 1;i <= 100;i++)
		 {
		  if(str2[j] == str[i])
		    break;
	     }
	     if(str2[j] == str[i])
		    break;
	}
	printf("%d",i+1);
} 
