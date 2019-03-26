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
map<int, bool> mp;
vector<int> ans;
bool vis[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int k;
        cin>>k;
        if(k == 1){
            int temp;
            cin>>temp;
            continue;
        }
        else{
            for(int j = 1; j <= k; j++){
                int temp;
                cin>>temp;
                mp[temp] = 1;
            }
        }
    }
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
        int temp;
        cin>>temp;
        if(!vis[temp] && mp[temp] != 1){
            ans.push_back(temp);
        }
        vis[temp] = 1;
    }
    if(ans.size() == 0){
        cout<<"No one is handsome";
    }
    else{
        cout<<ans[0];
        int siz = ans.size();
        for(int i = 1; i < siz; i++){
            cout<<" "<<ans[i];
        }
    }
    return 0;
}