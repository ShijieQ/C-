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
const int maxn = 500+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
vector<int> v[maxn];
int vis[maxn];
map<int, int> mp;

int main(){
    int V, E, K;
    cin>>V>>E>>K;
    for(int i = 1; i <= E; i++){
        int l, r;
        cin>>l>>r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
        memset(vis, 0, sizeof(vis));
        mp.clear();
        for(int j = 1; j <= V; j++){
            int temp;
            cin>>temp;
            vis[j] = temp;
            mp[temp] = 1;
        }
        if(mp.size() != K){
            cout<<"No"<<endl;
        }
        else{
            bool flag = 0;
            for(int j = 1; !flag && j <= V; j++){
                int siz = v[j].size();
                for(int k = 0; !flag && k < siz; k++){
                    int nod = v[j][k];
                    if(vis[j] == vis[nod]){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}