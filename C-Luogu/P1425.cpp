#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;

int main(){
    long long int a, b, c, d;
    cin>>a>>b>>c>>d;
    long long int ans = (c*60+d - a*60-b);
    cout<<ans/60<<" "<<ans%60<<endl;
    return 0;
}