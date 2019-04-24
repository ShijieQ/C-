#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;
int a[maxn], b[maxn];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, m, y;
        cin>>n>>m>>y;
        double suma = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            suma += a[i];
        }
        double sumb = 0;
        for(int i = 1; i <= m; i++){
            cin>>b[i];
            sumb += b[i];
        }
        double ans = (suma + sumb)/n;
        if(ans <= y)    cout<<"Go"<<endl;
        else            cout<<"Wait"<<endl;
    }
    return 0;
}