#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c) != EOF && !(a == 0 && b == 0 && c == 0))
    {
        int m = a / b;
        cout<<m<<".";
        int x = a % b;
        for(int i = c; i >= 0; i--)
        {
            m = x*10/b;
            x = x*10%b;
            if(i-1 > 0) cout<<m;
            else{
                if(i) continue;
                if(m>5) cout<<m+1;
                else cout<<m;}
        }
    }
    return 0;
}
