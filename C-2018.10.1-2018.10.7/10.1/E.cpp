#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+10;
int a[maxn];

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+m);
    long long int ans = 1;
    for(int i = 0; i < m-1; i++){
        if(a[i+1] - a[i] > n)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}