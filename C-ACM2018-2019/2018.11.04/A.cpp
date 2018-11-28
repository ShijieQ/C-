#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long maxn = 1e12+5;

long long int gcd(long long int a, long long int b){
    //cout<<1<<endl;
    return b ? gcd(b, a%b):a;
}

int solve(long long int a, long long int b){
    if(!b){
        return 0;
    }
    else{
        long long int k = gcd(a, b);
        long long int ak = a/k;
        long long int bk = b/k;
        for(int i = 2; i*i <= ak; i++){
            if(!(ak%i)){
                continue;
            }
            else{
                
            }
        }
    }
}

int main(){
    long long int x, y;
    cin>>x>>y;
    cout<<solve(x, y)<<endl;
    return 0;
}
/*
f(a, b) = 1 + f(a, b - gcd(a, b))
 : a = k1 * gcd(a, b)
   b = k2 * gcd(a, b)
   f(a, b) = 1 + f(k1*gcd(a, b), (k2-1)*gcd(a, b))
*/ 

