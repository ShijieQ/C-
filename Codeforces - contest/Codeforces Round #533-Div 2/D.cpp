#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;
char map[maxn][maxn];
int s[10];
queue< pair< pair<int, int>, int> > player[10], shit;
int ans[10];

int main(){
    /*
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    */
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= p; i++){
        scanf("%d", &s[i]);
    }
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            map[i][j] = getchar();
            if(map[i][j] - '0'>= 1 && map[i][j] - '0' <= p){
                player[map[i][j] - '0'].push(make_pair(make_pair(i, j), 1));
            }
        }
        getchar();
    }
    bool flag = 1;
    while(flag){
        flag = 0;
        for(int i = 1; i <= p; i++){
            while(!player[i].empty()){
                shit.push(player[i].front());
                player[i].pop();
            }
            while(!shit.empty()){
                pair< pair<int, int>, int> temp = shit.front();
                shit.pop();
                int x = temp.first.first, y = temp.first.second;
                if(x-1 >= 1 && map[x-1][y] == '.'){
                    map[x-1][y] = i + '0';
                    if(temp.second < s[i]){
                        shit.push(make_pair(make_pair(x-1, y), temp.second+1));
                    }
                    else{
                        player[i].push(make_pair(make_pair(x-1, y), 1));
                    }
                    flag = 1;
                }
                if(x+1 <= n && map[x+1][y] == '.'){
                    map[x+1][y] = i + '0';
                    if(temp.second < s[i]){
                        shit.push(make_pair(make_pair(x+1, y), temp.second+1));
                    }
                    else{
                        player[i].push(make_pair(make_pair(x+1, y), 1));
                    }
                    flag = 1;
                }
                if(y-1 >= 1 && map[x][y-1] == '.'){
                    map[x][y-1] = i + '0';
                    if(temp.second < s[i]){
                        shit.push(make_pair(make_pair(x, y-1), temp.second+1));
                    }
                    else{
                        player[i].push(make_pair(make_pair(x, y-1), 1));
                    }
                    flag = 1;
                }
                if(y+1 <= m && map[x][y+1] == '.'){
                    map[x][y+1] = i + '0';
                    if(temp.second < s[i]){
                        shit.push(make_pair(make_pair(x, y+1), temp.second+1));
                    }
                    else{
                        player[i].push(make_pair(make_pair(x, y+1), 1));
                    }
                    flag = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] - '0'>= 1 && map[i][j] - '0' <= p){
                ans[map[i][j] - '0']++;
            }
        }
    }
    cout<<ans[1];
    for(int i = 2; i <= p; i++){
        cout<<" "<<ans[i];
    }
    return 0;
}