#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;

int main(){
    long long int m, x;
    double n, d;
    cin>>n>>m>>d>>x;
    if(!d){
        cout<<ceil(m/n)<<endl;
    }
    else{
        double temp = n*n/d/d - n/d + 0.25 + m*2/d;
        int ans = ceil(0.5 - n/d + sqrt(temp));
        cout<<ans<<endl;
    }
    return 0;
}