#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000+50;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        long long int ans = (m-1)*n + (m & 1 ? n : 1) - 2;
        cout<<ans<<endl;
    }
    return 0;
}