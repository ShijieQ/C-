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
const int maxn = 1e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
bool F[maxn];
int b[4];
int n;
int l, r;
int vis[maxn];

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
    for(int i = 0; i < 1000; i++){
        F[i] = 1;
    }
}

int BFS(){
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > s;
    s.push(make_pair(l, 0));
    vis[l] = 1;
    while(!s.empty()){
        int k = s.front().first;
        int tim = s.front().second;
        s.pop();
        if(k == r)  return tim;
        int a[] = {k/1000, k/100%10, k/10%10, k%10};
        for(int i = 0; i < 4; i++){
            int pre = a[i];
            for(int j = 0; j <= 9; j++){
                if(j != a[i]){
                    a[i] = j;
                    int temp = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
                    if(!F[temp] && !vis[temp]){
                        vis[temp] = 1;
                        s.push(make_pair(temp, tim+1));
                    }
                    if(temp == r){
                        return tim+1;
                    }
                }
            }
            a[i] = pre;
        }
    }
    return -1;
}

int main(){
    init();
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &l, &r);
        if(l > r)   swap(l, r);
        b[0] = r/1000, b[1] = r/100%10, b[2] = r/10%10, b[3] = r%10;
        int ans = BFS();
        if(ans == -1){
            cout<<"Impossible"<<endl;
        }  
        else{
            cout<<ans<<endl;
        }
    }    
    return 0;
}