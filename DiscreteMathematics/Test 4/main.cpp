#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e4+10;
bool mp[maxn][maxn];
bool vis[maxn];
string ans = "";
int n;
int allroute = 0;
int fir = 0;

void create(){
    srand((int)time(NULL));
    for(int i = 1; i <= n; i++){
        mp[i][i] = 0;
        for(int j = 1; j < i; j++){
            int tem = 1 + rand()%100;
            if(tem < 70){
                mp[i][j] = 1;
                mp[j][i] = 1;
                allroute++;
            }
            else {
                mp[i][j] = 0;
                mp[j][i] = 0;
            }
        }
    }
}

void OutputMatrix(){
    cout<<"  ";
    for(int i = 1; i <= n; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 1; i <= n; i++){
        cout<<i<<" ";
        for(int j = 1; j <= n; j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
}

void nodeDfs(int k){
    vis[k] = 1;
    for(int i = 1; i <= n; i++){
        if(mp[k][i] && !vis[i]){
            nodeDfs(i);
        }
    }
}

bool checkConnect(){
    nodeDfs(n);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}

int checkEulerPath(){
    if(!checkConnect()){
        return 0;
    }
    int oddnode = 0;
    for(int i = 1; i <= n; i++){
        int degree = 0;
        for(int j = 1; j <= n; j++){
            if(mp[i][j]){
                degree++;
            }
        }
        if(degree & 1){
            fir = i;
            oddnode++;
        }
    }
    if(oddnode == 0){
        return 1;
    }
    else if(oddnode == 2){
        return -1;
    }
}

void dfs(int start, int end, string s, int step){
    if(step == allroute){
        ans = s;
        ans += char(end);
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(mp[end][i]){
            mp[end][i] = mp[i][end] = 0;
            dfs(end, i, s+char(end), step+1);
            mp[end][i] = mp[i][end] = 1;
        }
    }
    return ;
}

void OutputPath(){
    cout<<"路径为：";
    for(int i = 0; i < ans.length(); i++){
        cout<<int(ans[i])<<"->";
    }
    cout<<"End"<<endl;
}

int main(){
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);
    cin>>n;
    create();
    OutputMatrix();
    string tem = "";
    switch(checkEulerPath()){
        case 1:
            cout<<"存在欧拉回路."<<endl;
            for(int i = 1; i <= n; i++){
                if(mp[i][1]){
                    mp[i][1] = mp[1][i] = 0;
                    dfs(1, i, tem+char(1), 1);
                    mp[i][1] = mp[1][i] = 1;
                    break;
                }
            }
            OutputPath();
            break;
        case -1:
            cout<<"存在欧拉路."<<endl;
            ans = "";
            for(int i = 1; i <= n; i++){
                if(mp[fir][i]){
                    mp[fir][i] = mp[i][fir] = 0;
                    dfs(fir, i, tem+char(fir), 1);
                    mp[fir][i] = mp[i][fir] = 1;
                }
            }
            OutputPath();
            break;
        case 0:
            cout<<"图中不存在欧拉路."<<endl;
            break;
    }
    return 0;
}