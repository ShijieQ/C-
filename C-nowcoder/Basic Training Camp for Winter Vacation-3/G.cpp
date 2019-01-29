#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=20;
long long f[maxn][10];

void getdp() {
    f[0][0]=1;
    for (int i=1;i<20;i++) {
        for (int j=0;j<10;j++) {
            if (j == 6){ 
                f[i][j]=0;
            }
            else {
                for (int k=0;k<10;k++)
                    f[i][j]+=f[i-1][k];
            }
        }
    }
}

int a[maxn];
long long solve(long long n) {
    a[0] = 0;
    while (n){
        a[++a[0]] = n%10;
        n /= 10;
    }
    a[a[0]+1] = 0;
    long long ans = 0;
    for (int i = a[0]; i >= 1; i--) {
        for (int j = 0;j < a[i]; j++)
            if (j != 6)
                ans += f[i][j];
        if (a[i] == 6) 
            break;
    }
    return ans;
}

int main() {
    long long int n,m;
    getdp();
    cin>>n>>m;
    long long k1 = solve(m+1);
    long long k2 = solve(n);
    cout<<m-n-(k1-k2)+1<<endl;
    return 0;
}