#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000+10;

int main(){
    int n, a;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        int tem = 0;
        scanf("%d", &a);
        while(a){
            if(a%2 == 0){
                tem++;
            }
            a >>= 1;
            cnt++;
        }
        int t0 = cnt - tem;
        //cout<<t0<<endl;
        int ans = pow(2, t0);
        cout<<ans<<endl;
    }
    return 0;
}