#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
map<int, int> mp;

int cal(int a){
    int ans = a;
    while(a){
        ans += a%10;
        a /= 10;
    }
    return ans;
}

void sol(){
    for(int i = 1; i <= maxn; i++){
        int tem = cal(i);
        if(!mp[tem] || mp[tem] > i){
            mp[tem] = i;
        }
    }
}

int main(){
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
    sol();
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        cout<<mp[k]<<endl;
    }
}
