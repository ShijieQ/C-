#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int mod = 256;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int qpow(int a, int b){
    long long int ans = 1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main(){
    init();
    ull a, b, c, k;
    while(cin>>a>>b>>c>>k){
        if(!(a || b || c || k)){
            break;
        }
        k = cal(2, k);
        // ull x, y;
        // ull ans_ = exgcd(c, k, x, y);
        ull x, y, ans_;
        exgcd(c, k, ans_, x, y);
        if((b-a)%ans_){
            cout<<"FOREVER"<<endl;
        }
        else{
            ull ans = ((x * (b-a)/ans_)) % k;
            ans = (ans%(k/ans_) + k/ans_) % (k/ans_);
            cout<<ans<<endl;
        }
    }
}