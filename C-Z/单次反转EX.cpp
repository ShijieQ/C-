#include <stdio.h> 
#include <string.h>
int main()
{
    char strings[100]; 
	int i,t,n;
    gets(strings);
	n=strlen(strings); 
	i=n-1;
	while(i-->=0) //�Ӻ���ǰ�жϣ������ո�����һ������   
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

   }    //���λ�ھ�����ǰ��ĵ���   
	for(t=0;t<n;t++)
	{  
	printf("%c",strings[t]);    
	}     
	return 0; 
}
