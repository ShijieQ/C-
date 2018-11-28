#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+5;

int main(){
    int T;
    cin>>T;
    while(T--){
        unsigned long long int a, b, c, s;
        cin>>s>>a>>b>>c;
        unsigned long long int ans = s/c/a*b + s/c;
        cout<<ans<<endl;
    }
}