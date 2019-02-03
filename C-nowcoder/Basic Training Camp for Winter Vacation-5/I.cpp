#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 500+10;
char mp[maxn][maxn];
int ans[maxn];
int n, m;

void read(){
    cin>>n>>m;
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mp[i][j] = getchar();
        }
        getchar();
    }
}

void solve(){
    for(int i = 1; i <= m; i++){
        int x = 1, y = i;
        char status = 'D';
        if(mp[x][y] == '/' && status == 'D'){
                status = 'L';
        }
        else if(mp[x][y] == '\\' && status == 'D'){
                status = 'R';
        }
        while(x >= 1 && y >= 1 && x <= n && y <= m){
            if(status == 'D'){
                x++;
            }
            if(status == 'U'){
                x--;
            }
            if(status == 'L'){
                y--;
            }
            if(status == 'R'){
                y++;
            }
            if(!(x >= 1 && y >= 1 && x <= n && y <= m)){
                break;
            }

            if(mp[x][y] == '/' && status == 'D'){
                status = 'L';
            }
            else if(mp[x][y] == '/' && status == 'U'){
                status = 'R';
            }
            else if(mp[x][y] == '/' && status == 'L'){
                status = 'D';
            }
            else if(mp[x][y] == '/' && status == 'R'){
                status = 'U';
            }
            else if(mp[x][y] == '\\' && status == 'D'){
                status = 'R';
            }
            else if(mp[x][y] == '\\' && status == 'U'){
                status = 'L';
            }
            else if(mp[x][y] == '\\' && status == 'L'){
                status = 'U';
            }
            else if(mp[x][y] == '\\' && status == 'R'){
                status = 'D';
            }
        }
        if(x > n && status == 'D'){
            ans[i] = y;
        }
        else {
            ans[i] = -1;
        }
    }
    for(int i = 1; i <= m; i++){
        cout<<ans[i]<<endl;
    }
}

int main(){
    read();
    solve();
    return 0;
}