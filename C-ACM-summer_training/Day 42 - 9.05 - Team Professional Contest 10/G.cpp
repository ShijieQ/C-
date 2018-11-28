#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000+50;
pair<int, int> a[maxn];

bool cmp(pair<int, int> m, pair<int, int> n){
    return m.first > n.first;
}

int main(){
    int n;
    scanf("%d", &n);
    long long int v2 = 0;
    double ans2 = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i].first, &a[i].second);
        ans2 += double(v2*a[i].second) + 1.0/2*a[i].first*a[i].second*a[i].second;
        v2 += a[i].first*a[i].second;
    }
    sort(a+1, a+n+1, cmp);
    long long int v1 = 0;
    double ans1 = 0;
    for(int i = 1; i <= n; i++){
        ans1 += double(v1*a[i].second) + 1.0/2*a[i].first*a[i].second*a[i].second;
        v1 += a[i].first*a[i].second; 
    }
    printf("%.1lf\n", ans1-ans2);
}
