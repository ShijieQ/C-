#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e3+10;
char mp[maxn][maxn];
int n, m, r, c, x, y;
long long int ans = 0;
deque<pair<pair<int, int>, pair<int, int> > > q;
int fl[] = {-1, 1, 0, 0};
int fr[] = { 0, 0,-1, 1};
int sl[] = { 0, 0, 1, 0};
int sr[] = { 0, 0, 0, 1};

void read(){
    scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mp[i][j] = getchar();
        }
        getchar();
    }
}

void solve(){
    q.push_back(make_pair(make_pair(r, c), make_pair(0, 0)));
    while(!q.empty()){
        pair<int, int> fir = q.front().first, sec = q.front().second;
        q.pop_front();
        int fir_l = fir.first, fir_r = fir.second, sec_l = sec.first, sec_r = sec.second;
        if(sec_l > x || sec_r > y || fir_l > n || fir_l < 1 || fir_r  > m || fir_r < 1 || mp[fir_l][fir_r] != '.'){
            continue;
        }
        mp[fir_l][fir_r] = '+';
        ans++;
        for(int i = 0; i < 4; i++){
            if(i < 2)
                q.push_front(make_pair(make_pair(fir_l + fl[i], fir_r + fr[i]), make_pair(sec_l + sl[i], sec_r + sr[i])));
            else
                q.push_back(make_pair(make_pair(fir_l + fl[i], fir_r + fr[i]), make_pair(sec_l + sl[i], sec_r + sr[i])));
        }    
    }
    cout<<ans<<endl;
}

int main(){
    read();
    solve();
    return 0;
}