#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
    long long int ans = 0;
    long long int k = 0;
    for(int i = 1; i <= 12; i++){
        ans += 300;
        int a;
        cin>>a;
        ans -= a;
        if(ans < 0){
            cout<<-i<<endl;
            return 0;
        }
        k += ans/100;
        ans %= 100;
    }
    cout<<k*120+ans<<endl;
    return 0;
}