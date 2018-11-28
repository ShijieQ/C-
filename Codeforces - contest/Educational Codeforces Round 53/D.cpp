#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
    int n;
    long long int T;
    scanf("%d%lld", &n, &T);
    long long int sum = 0;
    int minn = INF;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        minn = min(minn, a[i]);
    }
    long long int ans = T/sum * n;
    T %= sum;
    while(T >= minn){
        int tem = 0;
        long long int k = 0;
        for(int i = 1; i <= n; i++){
            if(T >= a[i]){
                tem++;
                T -= a[i];
                k += a[i];
            }
        }
        ans += tem + T/k * tem;
        T %= k;
    }
    cout<<ans<<endl;
    return 0;
}