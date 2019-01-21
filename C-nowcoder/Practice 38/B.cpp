#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

long long int gcd(long long int a, long long int b){
    return b ? gcd(b, a%b):a;
}

int main(){
    long long int n, m, x, y, t;
    cin>>n>>m>>x>>y>>t;
    long long int a = m*(m-1)*x*(x-1) + n*(n-1)*y*(y-1);
    long long int b = (n-1)*(m-1)*(m*x + n*y);
    if(t){
        long long int temp = gcd(a, b);
        a /= temp; b/= temp;
        cout<<a<<"/"<<b<<endl;
    }
    else{
        printf("%.3f\n", a*1.0/b + 0.0005);
    }
    return 0;
}