#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;

int main(){
    int x, n;
    cin>>x>>n;
    long long int ans = (n/7)*1250;
    for(int i = x; i < x + n%7; i++){
        ans += (i == 6 || i == 7 || i == 13 || i == 14 ? 0:250);
    }
    cout<<ans<<endl;
    return 0;
}