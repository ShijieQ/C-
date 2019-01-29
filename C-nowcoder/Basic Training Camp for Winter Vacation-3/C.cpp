#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
bool vis[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n-1; i++){
        int a;
        cin>>a;
        vis[a] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}