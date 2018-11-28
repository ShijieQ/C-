#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

long long int check(long long int k, long long int n){
    long long int l = 0, r = n;
    while(l <= r){
        // cout<<l<<"  "<<r<<endl;
        long long int mid = (l+r)/2;
        if(mid*(mid-1) > k*2){
            r = mid - 1;
        }
        else if(mid*(mid-1) < k*2){
            l = mid + 1;
        }
        else{
            return n - mid;
        }
    }
    return n - l;
}

int main(){
    long long int m, n;
    cin>>n>>m;
    cout<<(n >= m*2 ? n - m*2 : 0)<<" "<<(m ? check(m, n) : n)<<endl;
    return 0;
}