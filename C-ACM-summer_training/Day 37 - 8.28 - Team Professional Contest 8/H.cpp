#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000+10;
const long long int INF = 0x7FFFFFFFFFFFFFFFLL;
int a[maxn];
int cnt[maxn];
int n;

long long int gcd(long long int a, long long int b){
    return b ? gcd(b, a%b):a;
}

long long int lcm(long long int a, long long int b){
    return a / gcd(a, b)*b;
}

void init(){
    cnt[0] = 0;
    for(int i = 1; i < maxn; i++){
        cnt[i] = i+cnt[i-1];    
    }
    
}

int judge(long long int k){
    for(int i = 1; i <= n; i++){
        long long int tem = k - cnt[a[i]];
        if(tem % a[i] != 0)
            return 0;
        if(tem / a[i] < 0)
            return 1;
    }
}

int main(){
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){

    }
}
