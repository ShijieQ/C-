#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
int t[6][2555];  
int main()  
{  
    int n;  
    while(scanf("%d",&n) != EOF)  
    {  
        memset(t,0,sizeof(t));  
        t[0][0] = 1;  
        t[1][0] = 1;  
        t[2][0] = 1;  
        t[3][0] = 1;  
        for(int i = 4;i < n;i++)  
        {  
            int carry = 0;  
            int k = i % 4;  
            for(int j = 0;j < 2500;j++)  
            {  
                int x = t[0][j] + t[1][j] + t[2][j] + t[3][j];  
                t[k][j] = x + carry;  
                carry = t[k][j] / 10;  
                t[k][j] %= 10;  
            }  
        }  
        int k = 2500;  
        while(t[(n - 1) % 4][--k] == 0);  
        for(int i = k;i >= 0;i--)  
        {  
            printf("%d",t[(n - 1) % 4][i]);  
        }  
          
        printf("\n");  
          
    }  
      
      
    return 0;  
}
