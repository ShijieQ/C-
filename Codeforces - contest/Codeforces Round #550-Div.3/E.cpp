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
#define Online

using namespace std;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int len;
    cin>>len;
    string s, t;
    cin>>s>>t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int c = 0, temp;
    string ans = "";
    for(int i = 0; i < len; i++){
        temp = (s[i] + t[i] + c - 2*'a');
        if(i < len - 1 && temp >= 26){
            c = 1;
            temp -= 26;
        }
        else{
            c = 0;
        }
        ans += temp;
    }
    reverse(ans.begin(), ans.end());
    c = 0;
    for(int i = 0; i < len; i++){
        temp = (ans[i] + c*26)/2;
        c = (ans[i] + c*26)%2;
        ans[i] = temp + 'a';
    }
    cout<<ans<<endl;
    return 0;
}