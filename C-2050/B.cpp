#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;

int main(){
    int T;
    cin>>T;
    while(T--){
        int year, month, day, h, m, s;
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &h, &m, &s);
        int ans = (100 - (m*60 + s)%100);
        if(ans == 100)  ans = 0;
        cout<<ans<<endl;
    }
    return 0;
}