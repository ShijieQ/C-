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
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
int a[maxn];
int ris[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > a[i-1]){
            ris[i] = ris[i-1] + 1;
        }
        else{
            ris[i] = 1;
        }
    }
    int ans = -INF;
    for(int i = 1; i <= n; i++){
        ans = max(ans, ris[i]);
    }
    cout<<ans<<endl;
    return 0;
}