#include <bits/stdc++.h>
using namespace std;
const int maxn = 32000 + 100;
typedef struct ite
{
    int v, p, q, cnt = 0;
    int ev[2], ep[2];
    bool maj;
} ite;
ite num[maxn];
int dp[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z)
        {
            num[z].ev[num[z].cnt] = x;
            num[z].ep[num[z].cnt] = x*y;
            num[z].cnt++;
        }
        else
        {
            num[i].v = x;
            num[i].p = x*y;
            num[i].maj = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if(!num[i].maj){
            continue;
        }
        for (int j = n; j >= 0; j--)
        {
            if (j >= num[i].v)
            {
                dp[j] = max(dp[j], dp[j - num[i].v] + num[i].p);
                if (num[i].cnt)
                {
                    if (num[i].cnt == 1)
                    {
                        if(j >= num[i].ev[0] + num[i].v){
                            dp[j] = max(dp[j], dp[j - num[i].v - num[i].ev[0]] + num[i].p + num[i].ep[0]);
                        }
                    }
                    else if (num[i].cnt == 2)
                    {
                        for (int k = 0; k < 2; k++)
                        {
                            if (j >= num[i].ev[k] + num[i].v)
                            {
                                dp[j] = max(dp[j], dp[j - num[i].v - num[i].ev[k]] + num[i].p + num[i].ep[k]);
                            }
                        }
                        if (j >= num[i].ev[0] + num[i].ev[1] + num[i].v)
                        {
                            dp[j] = max(dp[j], dp[j - num[i].v - num[i].ev[0] - num[i].ev[1]] + num[i].p + num[i].ep[0] + num[i].ep[1]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}