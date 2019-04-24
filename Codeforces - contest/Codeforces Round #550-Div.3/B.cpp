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
vector<int> odd;
vector<int> even;

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);    
    int n;
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        if(temp & 1){
            odd.push_back(temp);
        }
        else{
            even.push_back(temp);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int len_odd = odd.size(), len_even = even.size();
    long long int ans = 0;
    if(abs(len_odd - len_even) > 1){
        if(len_odd > len_even){
            for(int i = 0; i < len_odd - len_even - 1; i++){
                ans += odd[i];
            }
        }
        else{
            for(int i = 0; i < len_even - len_odd - 1; i++){
                ans += even[i];
            }
        }
    }
    else{
        ans = 0;
    }
    cout<<ans<<endl;
    return 0;
}