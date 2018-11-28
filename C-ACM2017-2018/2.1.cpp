#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int n,num = 0;
    while(scanf("%d",&n) != EOF){
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++){
                int k = i ^ j;
                if(k >= j && k <= n && k >= 1 && k <= n && i + k >j && j + k >i && i + j > k)
                    num++;
            }
    printf("%d\n",num);
    num = 0;
    }
    return 0;
}
