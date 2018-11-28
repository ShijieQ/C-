#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
const int mod = 256;

struct node
{
    char s[5];
    int a, qu;
    /*
    bool operator < (const struct node a) const{
        return qu < a.qu;
    }*/
}q[maxn];
set<int> ms[10005];
//map< pair<struct node, int>, int > mp;
int r = 0;
int n = 0;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        r = 0;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            char tem[5];
            scanf("%s",tem);
            strcpy(q[i].s,tem);
            if(!strcmp(tem,"add"))
            {
                scanf("%d",&q[i].a);
                q[i].qu = 0;
            }
            else
                scanf("%d %d",&q[i].a,&q[i].qu);
            ms[i].clear();
        }
        /*
        for(int i = 1; i <= n; i++){
            cout<<q[i].s<<" "<<q[i].a<<" "<<q[i].qu<<endl;
        }
        */
        int i=1;
        int flag=0;
        while(i<=n)
        {
        /*    pair<struct node, int> p;
            p.first = q[i];
            p.second = r;*/
            if(ms[i].find(r)!=ms[i].end())
            {
                flag=1;
                break;
            }
            if(!strcmp(q[i].s, "add"))
                r = (r+q[i].a)%mod;
            ms[i].insert(r);
            if(!strcmp(q[i].s, "beq"))
                if(q[i].a == r)
                    i=q[i].qu-1;
            if(!strcmp(q[i].s, "bne"))
                if(q[i].a != r)
                    i=q[i].qu-1;
            if(!strcmp(q[i].s, "blt"))
                if(r < q[i].a)
                    i=q[i].qu-1;
            if(!strcmp(q[i].s, "bgt"))
                if(r > q[i].a)
                    i=q[i].qu-1;
            i++;
        }
        if(!flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

