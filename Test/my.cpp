#include <bits/stdc++.h>

using namespace std;

const long long maxn = 50000;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long head[maxn], tot;

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}
struct edge
{
    long long v, next, w;
    edge(long long _v, long long _n, long long _w)
    {
        v = _v;
        next = _n;
        w = _w;
    }
    edge() {}
} e[maxn];

struct qnode
{
    long long v, w;
    qnode(long long _v, long long _w)
    {
        v = _v;
        w = _w;
    }
    qnode() {}
    bool operator<(const qnode &a) const
    {
        return w > a.w;
    }
};

void addedge(long long u, long long v, long long w)
{
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot++;
}

long long dis[maxn], pre[maxn];
bool vis[maxn];
priority_queue<qnode> que;
void dijkstra(long long n, long long beg)
{
    for (long long i = 0; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[beg] = 0;
    while (!que.empty())
        que.pop();
    que.push(qnode(beg, 0));
    qnode tmp;
    while (!que.empty())
    {
        tmp = que.top();
        long long u = tmp.v;
        que.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (long long i = head[u]; ~i; i = e[i].next)
        {
            long long v = e[i].v;
            long long w = e[i].w;
            if (!vis[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pre[v] = u;
                que.push(qnode(v, dis[v]));
            }
        }
    }
}

struct p
{
    long long u, v, w;
    p() {}
    p(long long _u, long long _v, long long _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
} bian[maxn];

pair<long long, long long> reco[maxn];
int main()
{
    init();
    long long n, m, s, t, cnt = 0;
    long long l;
    cin >> n >> m >> l >> s >> t;
    for (long long i = 0; i < m; i++)
    {
        cin >> bian[i].u >> bian[i].v >> bian[i].w;
        if (bian[i].w == 0)
        {
            reco[cnt].first = tot;
            reco[cnt].second = i;
            cnt++;
        }
        addedge(bian[i].u, bian[i].v, bian[i].w);
        addedge(bian[i].v, bian[i].u, bian[i].w);
    }
    dijkstra(n, s);
    if (dis[t] > l)
    {
        puts("NO");
        return 0;
    }
    else if (dis[t] == l)
    {
        puts("YES");
        for (int i = 0; i < m; i++)
        {
            printf("%I64d %I64d %I64d\n", bian[i].u, bian[i].v, bian[i].w ? bian[i].w : 1000000000000000000);
        }
        return 0;
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            e[reco[i].first].w = 1;
            e[reco[i].first + 1].w = 1;
        }
        dijkstra(n, s);
        if (dis[t] > l)
        {
            puts("NO");
            return 0;
        }
        else
        {
            for (int i = 0; i < cnt; i++)
            {
                e[reco[i].first].w = 0;
                e[reco[i].first + 1].w = 0;
            }
            long long int index = 0;
            dijkstra(n, s);
            while (dis[t] < l && index < cnt)
            {
                if (index != cnt - 1)
                {
                    e[reco[index].first].w = 1;
                    e[reco[index].first + 1].w = 1;
                    bian[reco[index].second].w = 1;
                }
                else
                {
                    e[reco[index].first].w = l-dis[t];
                    e[reco[index].first + 1].w = l-dis[t];
                    bian[reco[index].second].w = l-dis[t];
                }
                index++;
                dijkstra(n, s);
            }
            if (dis[t] == l)
            {
                puts("YES");
                for (int i = 0; i < m; i++)
                {
                    printf("%I64d %I64d %I64d\n", bian[i].u, bian[i].v, bian[i].w ? bian[i].w : 1000000000000000000);
                }
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}