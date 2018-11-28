#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool qipan[11][11];
char q[11][11];
int main()
{
    int n,x,y;
    while(scanf("%d %d %d",&n,&x,&y)&&(x!=0||y!=0||n!=0))
    {
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
                qipan[i][j]=false;
                q[i][j]='\0';
            }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                qipan[1+i][4+j]=true;
        for(int i=0;i<n;i++)
        {
            char a[2];
            int x1,y1;
            scanf("%s %d %d",a,&x1,&y1);
            q[x1][y1]=a[0];
        }
        for(int i=1;i<11;i++)
            for(int j=1;j<11;j++)
            {
                if(q[i][j]=='\0')
                    continue;
                else if(q[i][j]=='G')
                {
                    int o;
                    for(o=i-1;o>0&&q[o][j]=='\0';o--)
                        qipan[o][j]=false;
                    if(o>0)
                        qipan[o][j]=false;
                }
                else if(q[i][j]=='R')
                {
                    int o;
                    for(o=i-1;o>0&&q[o][j]=='\0';o--)
                        qipan[o][j]=false;
                    if(o>0)
                        qipan[o][j]=false;
                    for(o=i+1;o<11&&q[o][j]=='\0';o++)
                        qipan[o][j]=false;
                    if(o<11)
                        qipan[o][j]=false;
                    for(o=j-1;o>0&&q[i][o]=='\0';o--)
                        qipan[i][o]=false;
                    if(o>0)
                        qipan[i][o]=false;
                    for(o=j+1;o<11&&q[i][o]=='\0';o++)
                        qipan[i][o]=false;
                    if(o<11)
                        qipan[i][o]=false;
                }
                else if(q[i][j]=='C')
                {
                    int o;
                    for(o=i-1;o>0&&q[o][j]=='\0';o--);
                    o--;
                    for(;o>0&&q[o][j]=='\0';o--)
                        qipan[o][j]=false;
                    if(o>0)
                        qipan[o][j]=false;
                    for(o=i+1;o<11&&q[o][j]=='\0';o++);
                    o++;
                    for(;o<11&&q[o][j]=='\0';o++)
                        qipan[o][j]=false;
                    if(o<11)
                        qipan[o][j]=false;
                    for(o=j-1;o>0&&q[i][o]=='\0';o--);
                    o--;
                    for(;o>0&&q[i][o]=='\0';o--)
                        qipan[i][o]=false;
                    if(o>0)
                        qipan[i][o]=false;
                    for(o=j+1;o<11&&q[i][o]=='\0';o++);
                    o++;
                    for(;o<11&&q[i][o]=='\0';o++)
                        qipan[i][o]=false;
                    if(o<11)
                        qipan[i][o]=false;
                }
                else if(q[i][j]=='H')
                {
                    if(i>2&&q[i-1][j]=='\0')
                        qipan[i-2][j-1]=qipan[i-2][j+1]=false;
                    if(i<9&&q[i+1][j]=='\0')
                        qipan[i+2][j-1]=qipan[i+2][j+1]=false;
                    if(j>2&&q[i][j-1]=='\0')
                        qipan[i-1][j-2]=qipan[i+1][j-2]=false;
                    if(j<9&&q[i][j+1]=='\0')
                        qipan[i-1][j+2]=qipan[i+1][j+2]=false;
                }
            }
        bool jud=false;
        for(int i=x+1;i<11&&(q[i][y]=='\0'||q[i][y]=='G');i++)
            if(q[i][y]=='G')
            {
                jud=true;
                break;
            }
        if(qipan[x-1][y]||qipan[x+1][y]||qipan[x][y-1]||qipan[x][y+1]||jud)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
