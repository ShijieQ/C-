#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000+50;

pair<int, int> a[maxn];
int ans[maxn];

bool cmp(pair<int, int> m, pair<int, int> n){
    return m.first == n.first ? m.second < n.second:m.first < n.first;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a+1, a+n+1, cmp);
    for(int i = 1, k = n; i <= n; i++){
        ans[a[i].second] = k--;
    }
    printf("%d", ans[1]);
    for(int i = 2; i <= n; i++){
        printf(" %d", ans[i]);
    }
    printf("\n");
}
/*
4
1 2 2 1
*/