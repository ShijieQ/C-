#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    long long n,k,i;
    while(scanf("%I64d%I64d",&n,&k) != EOF)
    {
        int flag = 0;
        for(i = 1; i <= k; i++)
            if(n % i != i -1){
//                cout<<"No"<<endl;
                flag = 1;
                break;
            }
        if(flag) printf("No\n");
        else printf("Yes\n");
//            cout<<"Yes"<<endl;
    }
    return 0;
}
