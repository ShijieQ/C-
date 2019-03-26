#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
const int maxn = 1000+10;
bool mp[maxn];
 
int main(){
    string s;
    while(cin>>s){
        memset(mp, 0, sizeof(mp));
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(!mp[s[i]]){
                cout<<s[i];
                mp[s[i]] = 1;
            }
        }
        cout<<endl;
    }
    return 0;
}