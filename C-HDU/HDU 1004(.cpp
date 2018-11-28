#include <string>  
#include <stdio.h>  
#include <iostream>  
#include <map>  
using namespace std;  
int main()  
{  
    int n;  
    string ballon;  
    while(cin >> n,n)  
    {  
        map<string, int> m;  
        int N=n;  
        while(N--)  
        {  
            cin >> ballon;  
            ++m[ballon];  
        }  
        map<string,int>::iterator p;  
        int maxx=0;  
        string max_ballon;  
        for(p=m.begin(); p!=m.end(); ++p)  
        {  
            if(p->second>maxx)  
            {  
                maxx=p->second;  
                max_ballon=p->first;  
            }  
        }  
        cout << max_ballon << endl;  
    }  
    return 0;  
}
