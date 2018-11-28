#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e6+10;
double a[maxn];

void init(){
    a[0] = 0.0;
    double ans = 0;
    int cnt = 1;
    for(int i = 1; i <= 100000000; i++){
        ans += 1.0/i;
        if(i%50 == 0){
            a[cnt++] = ans;
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        int n;
        scanf("%d", &n);
        int k = n/50;
        double ans = a[k];
        for(int i = 50*k+1; i <= n; i++){
            ans += 1.0/i;
        }
        printf("Case %d: %.10f\n", t, ans);
    }
}