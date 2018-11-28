#include<map>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000000+100;
const int INF = 0x3f3f3f3f;
int a[maxn];
int s[maxn];

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int m, Q;
    while(cin>>m>>Q){
        map<int, int> mp;
        if(m == 0 && Q == 0){
            break;
        }
        for(int i = 1; i <= m; i++){
            cin>>a[i];
            s[i] = 0;
        }
        s[m] = INF;
        mp[a[m]] = m;
        for(int i = m-1; i >= 1; i--){
            if(mp[a[i]]){
                s[i] = min(mp[a[i]], s[i+1]);
            }else{
                s[i] = s[i+1];
            }
            mp[a[i]] = i;
        }
        for(int i = 1; i <= Q; i++){
            int c, d;
            cin>>c>>d;
            if(d < s[c]){
                cout<<"OK"<<endl;
            }else{
                cout<<a[s[c]]<<endl;
            }
        }
        cout<<endl;
    }
}