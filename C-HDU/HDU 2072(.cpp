#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
 
int main()
{
    char s[1000];
    set<string> st;
    string ss;
    while(gets(s)&&strcmp(s,"#")!=0)
    {
        int len=strlen(s);
        s[len]=' ';//s[len]ԭ����'\0'
        ss="";
        for(int i=0;i<=len;i++)
        {
            if(s[i]!=' ')
            {
                ss+=s[i];
            }
            else
            {
                if(ss.length())//�п������������ո�
                 st.insert(ss);
                ss="";
            }
 
        }
        printf("%d\n",st.size());
        st.clear();
    }
    return 0;
}

