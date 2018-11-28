#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string s1,s2,s3,s4;
const int maxn = 10000;
int a[maxn];
int b[maxn];
int c[maxn];

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 0;i < n;i++)
        {
            cin >> s1 >> s2;
            s3 = s1;
            s4 = s2;
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            memset(a,0,4*maxn);
            memset(b,0,4*maxn);
            memset(c,0,4*maxn);
            for(int i = 0;i < s1.length();i++)
            {
                a[i] = s1[i] - '0';
            }
            for(int i = 0;i < s2.length();i++)
            {
                b[i] = s2[i] - '0';
            }
            for(int i = 0;i < maxn;i++)
            {
                if(c[i] >= 10)
                {
                    c[i + 1] += 1;
                    c[i] -= 10;
                }
                c[i] = c[i] + a[i] + b[i];
                if(c[i] >= 10)
                {
                    c[i + 1] += 1;
                    c[i] -= 10;
                }
            }
            int len = maxn;
            while(c[len] == 0 && len > 0)
            {
                len--;
            }
            if(i != 0)
                cout << endl;
            cout << "Case " << i + 1 << ":" << endl;
            cout << s3 << " + " << s4 << " = ";
            do
            {
                cout << c[len];
            }while(len-- > 0);
            cout << endl;
        }
    }
}