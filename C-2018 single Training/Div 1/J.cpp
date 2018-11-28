#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 85;

int main(){
    freopen("J.in", "r", stdin);
    freopen("J.out", "w", stdout);
    int n;
    cin>>n;
    int flagg = 1;
    while(n--){
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 1; i <= s.length(); i++){
            if(s.length() % i != 0){
                continue;
            }
            if(ans){
                break;
            }
            string tem = s.substr(0, i);
            int flag = 0;
            for(int j = 0; j < s.length(); j += i){
                if(tem != s.substr(j, i)){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                ans = i;
            }
        }
        if(flagg){
            cout<<ans<<endl;
            flagg = 0;
        }
        else{
            cout<<endl<<ans<<endl;
        }
    }
}