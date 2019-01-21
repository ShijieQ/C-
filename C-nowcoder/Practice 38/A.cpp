#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
double a[maxn];

bool cmp(double t1, double t2){
    return t1 > t2;
}

int main(){
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &a[i]);
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        if(a[i] > x){
            x = (a[i] + x)/2;
        }
    }
    printf("%.3f\n", x);
    return 0;
}