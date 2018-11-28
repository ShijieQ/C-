#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;
int pre[maxn];

bool cmp(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        memset(pre, 0, sizeof(pre));
        int n, m, k;
        cin>>n>>m>>k;
        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            pre[a]++;
            pre[b]++;
        }
        sort(pre, pre+n, cmp);
        int l = min(k, m-pre[0]);
        cout<<n-m-1+pre[0]+l<<endl;
    }
    return 0;
}