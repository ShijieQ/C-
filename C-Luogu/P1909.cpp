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
    long long int n;
    cin>>n;
    long long int ans = INF;
    for(int i = 1; i <= 3; i++){
        int a, b;
        cin>>a>>b;
        ans = min(ans, (n/a + (n%a>0))*b);
    }
    cout<<ans<<endl;
    return 0;
}