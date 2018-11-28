#include <stdio.h>
#include <malloc.h> 
#include <iostream>
using namespace std;
#define Null 0


char*StrCpy(char* src)
{
    int len=0,i=0;
    while(src[len]!= '\0')
    {
        len++;
    }
    
    char *dst=(char*)malloc(sizeof(char)*(len+1));
    for(i=0;i<len;i++)
    {
        dst[i]=src[i];
    }
    
    dst[len]='\0';
    return dst;
}
int main()
{
    char*src;
    src = (char *)malloc(sizeof(char) * 100000);
    cin>>src;
    
    char* dst=StrCpy(src);
    
    cout<<dst<<endl;
    
    if(dst!=Null)
      free(dst);
	      
    return 0;
}
