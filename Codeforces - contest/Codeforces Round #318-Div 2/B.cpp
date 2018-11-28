#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 4000+5;
const int INF = 0x3f3f3f3f;
bool mp[maxn][maxn];
int relate[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num, n;
    cin>>num>>n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin>>a>>b;
        mp[a][b] = true;
        mp[b][a] = true;
        relate[a]++;
        relate[b]++;    
    }
    int ans = INF;
    for(int i = 1; i <= num; i++){
        for(int j = i+1; j <= num; j++){
            if(mp[i][j]){
                for(int k = j+1; k <= num; k++){
                    if(mp[i][k] && mp[j][k]){
                        ans = min(ans, relate[i]+relate[j]+relate[k]);
                    }
                }
            }
        }
    }
    if(ans == INF){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans-6<<endl;
    }
    return 0;
}