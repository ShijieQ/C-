#include<cmath>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int mod = 1000;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int sol(long long int a, long long int b, int t){
    long long int first = a;
    long long int second = b;
    long long int ans1 = 1;
    a %= mod;
    while(b){
        if(b & 1)
            ans1 = (ans1 * a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    a = first;
    b = second;
    double c = b*log10(a);
    int x = int(c);
    double y = c-x;
    int ans2 = int (pow(10, y)*100);
    cout<<"Case "<<t<<": "<<setw(3)<<setfill('0')<<ans2<<" "<<setw(3)<<setfill('0')<<ans1<<endl;
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        long long int n, k;
        cin>>n>>k;
        sol(n, k, t);
    }
}