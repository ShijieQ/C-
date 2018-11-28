#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+5;

int main(){
    int T;
    cin>>T;
    while(T--){
        map<int, int> mp;
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++){
            int tem;
            cin>>tem;
            mp[tem] = 1;
        }
        for(int i = 1; i <= n; i++){
            int tem;
            cin>>tem;
            if(!mp[tem]){
                mp[tem] = 1;
            }else{
                mp[tem]++;
            }
            if(mp[tem] > 1){
                cout<<tem<<endl;
            }
        }
    }
}