#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    int x;
    int y;
}a[100005];

bool cmp(struct node a, struct node b){
    return a.x == b.x?a.y<b.y:a.x<b.x;
}

int len(struct node a, int X, int Y){
    return min(a.x, min(a.y, min(X-a.x, Y-a.y)));
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int x, y, n;
        cin>>x>>y>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i].x>>a[i].y;
        }
//        sort(a+1, a+n+1);
        long long int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += len(a[i], x, y);
        }
        cout<<ans<<endl;
    }
    return 0;
}