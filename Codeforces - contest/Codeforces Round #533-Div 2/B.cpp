#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
map<char, int> mp;
set<char> t;

int main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int len = s.length();
    int cnt = 1;
    t.insert(s[0]);
    for(int i = 1; i < len; i++){
        t.insert(s[i]);
        if(s[i] == s[i-1]){
            cnt++;
        }
        else {
            mp[s[i-1]] += cnt/k;
            cnt = 1;
        }
    }
    mp[s[n-1]] += cnt/k;
    int ans = 0;
    for(auto &v:mp){
        ans = max(v.second, ans);
    }
    cout<<ans<<endl;
    return 0;
}