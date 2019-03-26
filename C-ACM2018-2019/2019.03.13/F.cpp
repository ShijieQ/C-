#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<time.h>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+100;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
string s;
int len;
const unsigned long long base = 233;
unsigned long long Hash[maxn];
unsigned long long p[maxn];

void init(){
    p[0] = 1;
    Hash[0] = 0;
    for(int i = 1; i <= len; i ++)
        p[i] = p[i-1] * base;
    for(int i = 1; i <= len; i ++)
        Hash[i] = Hash[i - 1] * base + (s[i] - 'a');
}
 
unsigned long long get(int l, int r){
    return Hash[r] - Hash[l - 1] * p[r - l + 1];
}

int main(){
    cin>>s;
    len = s.length();
    s = " " + s;
    init();
    int T;
    cin>>T;
    while(T--){
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1, r1) == get(l2, r2)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}