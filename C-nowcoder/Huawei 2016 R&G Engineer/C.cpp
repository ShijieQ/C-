#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10;
int mp[maxn][maxn];
vector<pair<int, int> > vec;
int siz = 0;
// int test = 0;

void read(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin>>mp[i][j];
            if(mp[i][j] == 0){
                vec.push_back(make_pair(i, j));
            }
        }
    }
    siz = vec.size();
}

bool check(int k, int x, int y){
    for(int i = 1; i <= 9; i++){
        if(mp[x][i] == k || mp[i][y] == k){
            // if(x == 3 && y == 4){
            //     cout<<"k = "<<k<<endl;
            // }
            return 0;
        }
    }
    int pos_X = (x - 1)/3, pos_Y = (y - 1)/3;
    for(int i = pos_X*3 + 1; i <= pos_X*3 + 1 + 2; i++){
        for(int j = pos_Y*3 + 1; j <= pos_Y*3 + 1 + 2; j++){
            if(mp[i][j] == k){
                return 0;
            }
        }
    }
    return 1;
}

void output(){
    for(int i = 1; i <= 9; i++){
        cout<<mp[i][1];
        for(int j = 2; j <= 9; j++){
            cout<<" "<<mp[i][j];
        }
        cout<<endl;
    }
}

bool solve(int num){
    // test++;
    if(num == siz){
        return 1;
    }
    int i = vec[num].first, j = vec[num].second;
    for(int k = 1; k <= 9; k++){
        if(check(k, i, j)){
            // cout<<"num = "<<num<<" i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
            mp[i][j] = k;
            if(solve(num + 1) == 1){
                // cout<<"check"<<endl;
                return 1;
            }
                // if(i == 3 && j == 4){
                //     cout<<"check"<<endl;
                // }
            mp[i][j] = 0;
        }
    }
    return 0;
}

int main(){
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    read();
    //cout<<"siz = "<<siz<<endl;
    solve(0);
    //cout<<vec[12].first<<" "<<vec[12].second<<endl;
    output();
    //cout<<"test = "<<test<<endl;
    return 0;
}
/*
0 9 5 0 2 0 0 6 0
0 0 7 1 0 3 9 0 2
6 0 0 0 0 5 3 0 4
0 4 0 0 1 0 6 0 7
5 0 0 2 0 7 0 0 9
7 0 3 0 9 0 0 2 0
0 0 9 8 0 0 0 0 6
8 0 6 3 0 2 1 0 5
0 5 0 0 7 0 2 8 3
*/
/*
3 9 5 7 2 4 8 6 1
4 8 7 1 6 3 9 5 2
6 2 1 9 8 5 3 7 4
9 4 2 5 1 8 6 3 7
5 6 8 2 3 7 4 1 9
7 1 3 4 9 6 5 2 8
2 3 9 8 5 1 7 4 6
8 7 6 3 4 2 1 9 5
1 5 4 6 7 9 2 8 3
*/