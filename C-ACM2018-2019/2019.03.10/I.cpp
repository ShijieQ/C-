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
const int maxn = 1e5+10;
int n, k;
int pos[26];
string s;

int main(){
    cin>>n>>k>>s;
    int len = s.length();
    for(int i = 0; i < len; i++){
        pos[s[i] - 'A']++;
    }
    int ans = INF;
    for(int i = 0; i < k; i++){
        ans = min(pos[i], ans);
    }
    cout<<ans*k<<endl;
    return 0;
}