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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;

int main(){
    int N;
    cin>>N;
    while(N--){
        for(int i = 1; i <= 4; i++){
            string s;
            cin>>s;
            int len = s.length();
            for(int i = 0; i < len; i++){
                if(s[i] == 'T'){
                    cout<<s[i-2] - 'A' + 1;
                    break;
                }
            }
        }
    }
    return 0;
}