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
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+10;
string a, b;
int len;

int main(){
    cin>>len>>a>>b;
    long long int ans = 0;
    for(int i = 0; i < len-1; i++){
        if(a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]){
            a[i] = b[i];
            a[i+1] = b[i+1];
            ans++;
        }
        if(a[i] != b[i]){
            a[i] = b[i];
            ans++;
        }
    }
    if(a[len-1] != b[len-1]){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}