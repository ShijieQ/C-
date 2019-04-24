#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 50+5;

int main(){
    int n, k, l = 0;
    string s;
    cin>>n>>k>>s;
    for(int i = 0; i < n-1; i++){
        if(s.substr(0, i+1) == s.substr(n-i-1)){
            l = i+1;
        }
    }
    cout<<s;
    for(int i = 0; i < k-1; i++){
        cout<<s.substr(l);
    }
    return 0;
}