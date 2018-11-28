#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
    int b[1010];
    int n,k,t;
    stack<int> s;
    while(scanf("%d",&n) != EOF && n)
    {
        while(1)
        {
            while(!s.empty())
            {
                s.pop();
            }
            k=t=0;
            scanf("%d",&b[0]);
            if(b[0]==0)
                break;
            for(int i=1;i<n;i++)
                scanf("%d",&b[i]);
            for(int i=1;i<=n;i++)
            {
                s.push(i);
//                printf("%2d",s.top());
                while(!s.empty()&&s.top()==b[k])
                {
                    k++;
                    s.pop();
                }
            }
            printf("%s\n",s.empty()?"Yes":"No");
        }
        printf("\n");
    }
}
