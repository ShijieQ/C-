#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
pair<int, string> q[maxn]; 
map<string, int> mans;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    int ans = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>q[i].first;
        if(q[i].first == 2){
            cin>>q[i].second;
        }
    }
    mans.clear();
    for(int i = n; i >= 1; i--){
        int siz = mans.size();
        string temp;
        while(q[i].first != 1 && i >= 1){
            if(!mans[q[i].second]){
                temp = q[i].second;
            }
            i--;
        }
        mans[temp] = 1;
        if(mans.size() != siz)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}