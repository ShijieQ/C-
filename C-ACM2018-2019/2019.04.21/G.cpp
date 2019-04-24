#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;

bool check(long long int n){
    if(n == 1){
        return false;
    }
    for(long long int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long int l, r;
    cin>>l>>r;
    long long int prime_l, prime_r;
    for(long long int i = l; i <= r; i++){
        if(check(i) == true){
            prime_l = i;
            break;
        }
    }
    for(long long int i = r; i >= l; i--){
        if(check(i) == true){
            prime_r = i;
            break;
        }
    }
    cout<<prime_r - prime_l<<endl;
    return 0;
}