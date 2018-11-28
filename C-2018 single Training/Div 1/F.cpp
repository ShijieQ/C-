#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 105;
map<string, int> mp;

int main(){
    /*
    freopen("F.in", "r", stdin);
    freopen("F.out", "w", stdout);
    */
    int n;
    string s;
    cin>>n;
    while(n--){
        mp.clear();
        cin>>s;
        int len = s.length();
        for(int i = 0; i < len; i++){
            s = s[len-1] + s.substr(0, len-1);
        //    cout<<s<<endl;
            mp[s]++;
        }
        for(auto &v : mp){
            cout<<v.first<<endl;
            break;
        }
    }
}