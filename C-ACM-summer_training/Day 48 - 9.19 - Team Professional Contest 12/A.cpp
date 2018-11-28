#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 100;
ll st[maxn], ed[maxn];
map<ll, int> mp;
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> st[i];
    for (int i = 0; i < m; i++)
        cin >> ed[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(ed[j]-st[i] > 0) 
            {
                mp[ed[j]-st[i]]++;
            }
        }
    }
    pair<long long, int> p;
    for(auto &q : mp)
    {
        if(q.second > p.second){
            p.first = q.first;
            p.second = q.second;
        }
        if(q.second == p.second && q.first < p.first){
            p.first = q.first;
            p.second = q.second;
        }
    }
    cout << p.first << endl;
    return 0;
}