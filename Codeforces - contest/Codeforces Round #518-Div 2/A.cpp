#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long int maxn = 1e18+5;

int main(){
    unsigned long long int n, m, k, l;
    cin>>n>>m>>k>>l;
    if(m > n || k + l > n){
        cout<<"-1"<<endl;
        return 0;
    }
    unsigned long long int ans = (k+l)/m + ((k+l)%m ? 1:0);
    if(ans*m > n){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}