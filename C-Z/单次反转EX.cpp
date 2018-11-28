#include <stdio.h> 
#include <string.h>
int main()
{
    char strings[100]; 
	int i,t,n;
    gets(strings);
	n=strlen(strings); 
	i=n-1;
	while(i-->=0) //从后向前判断，遇到空格就输出一个单词   
   {  
     if(strings[i]==' ') 
    {         
       for(t=i+1;t<n;t++)
	   {
	     printf("%c",strings[t]);            
       } 
       printf(" ");             
       n=i;     
    }    

   }    //输出位于句子最前面的单词   
	for(t=0;t<n;t++)
	{  
	printf("%c",strings[t]);    
	}     
	return 0; 
}
