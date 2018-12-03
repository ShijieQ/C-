#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long int maxn = 1e12;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        long long int n;
        cin>>n;
        long long int ans1 = sqrt(n);//平方数的个数
        long long int ans2 = sqrt(n/2.0);//二倍平方数的个数
        cout<<"Case "<<t<<": "<<n-ans1-ans2<<endl;
    }
}