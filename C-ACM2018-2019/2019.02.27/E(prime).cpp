//http://codeforces.com/contest/500/problem/B
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 300+10;
bool mp[maxn][maxn];
int n;
int a[maxn];
int a_min[maxn];

bool check(){
    for(int i = 1; i <= n; i++){
        if(a[i] < a_min[i]){
            return 1;
        }
        else if(a[i] > a_min[i]){
            return 0;
        }
        else{
            continue;
        }
    }
    return 1;
}

void intcpy(bool flag){
    if(flag){
        for(int i = 0; i <= n; i++){
            a_min[i] = a[i];
        }
    }
    else {
        for(int i = 0; i <= n; i++){
            a[i] = a_min[i];
        }
    }
}

void read(){
    scanf("%d", &n);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        a[i] = temp;
    }
    intcpy(1);
    for(int i = 1; i <= n; i++){
        getchar();
        for(int j = 1; j <= n; j++){
            mp[i][j] = getchar() - '0';
        }
    }
}

void solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][k] && mp[k][j]){
                    mp[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[i][j]){
                swap(a[i], a[j]);
                if(check()){
                    intcpy(1);
                }
                else{
                    swap(a[i], a[j]);
                }
            }
        }
        intcpy(0);
    }
    cout<<a_min[1];
    for(int i = 2; i <= n; i++){
        cout<<" "<<a_min[i];
    }
    cout<<endl;
}

int main(){
    read();
    solve();
    return 0;
}