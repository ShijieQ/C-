                //TLE 
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10+2;
bool mp[maxn][maxn];
int n, m;
string ans;
bool flag = 0;

void dfs(int x, int y, string s, int step){
    //cout<<"x = "<<x<<", y = "<<y<<endl;
    mp[x][y] = 1;
    if(flag){
        return ;
    }
    if(step == n*m-1 && (x+y) == 1){
        if(x == 1 && y == 0){
            s += 'U';
        }
        if(x == 0 && y == 1){
            s += 'L';
        }
        ans = s;
        flag = 1;
        return ;
    }
    if(step >= n*m){
        return ;
    }
    if(x + 1 < n && !mp[x + 1][y]){
        dfs(x + 1, y, s + 'D', step+1);
    }
    if(x - 1 >= 0 && !mp[x - 1][y]){
        dfs(x - 1, y, s + 'U', step+1);
    }
    if(y + 1 < m && !mp[x][y + 1]){
        dfs(x, y + 1, s + 'R', step+1);
    }
    if(y - 1 >= 0 && !mp[x][y - 1]){
        dfs(x, y - 1, s + 'L', step+1);
    }
    mp[x][y] = 0;
}

int main(){
    cin>>n>>m;
    string temp = "";
    dfs(0, 0, temp, 0);
    if(flag){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    }
    return 0;
}