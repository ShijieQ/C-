#include<iostream>
#include<algorithm>
#define maxn 100000+5
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int a[maxn];
        int n, m;
        cin>>n>>m;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= m; i++){
            int tem1, tem2, k;
            cin>>tem1>>tem2;
            k = a[tem1];
            a[tem1] = tem2;
            int ans = 1, maxx = a[1];
            for(int i = 2; i <= n; i++){
                if(a[i] > maxx){
                    ans++;
                    maxx = a[i];
                }
            }
            cout<<ans<<endl;
            a[tem1] = k;
        }
    }
    return 0;
}