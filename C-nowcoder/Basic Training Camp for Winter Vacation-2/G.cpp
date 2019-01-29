#include <bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
void read(int &a)
{
    int d=1;
    a=0;
    char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=a*10+ch-'0';
    a*=d;
}
void write(int x)
{
    if(x<0)
        putchar(45),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
bool dfs(string s,string ss,int i,int j,int sum)
{
    if(sum>2)
        return 0;
    int len1=s.size();
    int len2=ss.size();
    if(i<len1||j<len2)
    {
        if(s[i]==ss[j])
            return dfs(s,ss,i+1,j+1,sum);
        else
        {
            bool a=dfs(s,ss,i+1,j,sum+1);
            bool b=dfs(s,ss,i,j+1,sum+1);
            bool c=dfs(s,ss,i+1,j+1,sum+1);
            if(a||b||c)
                return 1;
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s,ss;
    cin>>s>>ss;
    int len1=s.size();
    int len2=ss.size();
    if(fabs(len1-len2)>2)
    {
        printf("NO");
        return 0;
    }
    if(dfs(s,ss,0,0,0))
        printf("YES");
    else
        printf("NO");
    return 0;
}