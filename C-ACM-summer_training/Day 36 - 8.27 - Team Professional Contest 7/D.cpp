#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 5000000+50;
int a[500000+5];
int n, b;

bool judge(int c){
    long long int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += a[i]/c + (a[i]%c?1:0);
    }
    return cnt > b;
}

int main(){
    while(scanf("%d %d", &n, &b) != EOF && n != -1 && b != -1){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int l = 1, r = maxn, mid;
        while(l <= r){
            mid = (l+r)>>1;
            if(judge(mid)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        printf("%d\n", l);
    }
}