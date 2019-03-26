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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
deque<string> q;
map<string, int> vis;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        q.push_front(s);
    }
    while(!q.empty()){
        if(!vis[q.front()]){
            cout<<q.front()<<endl;
            vis[q.front()] = 1;
        }
        q.pop_front();
    }
    return 0;
}