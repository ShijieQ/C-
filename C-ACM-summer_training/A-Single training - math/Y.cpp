#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000;
bool F[maxn];
int notprime[maxn];
int num = 0;
set<unsigned long long int> s;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
    for(int i = 2; i < maxn; i++){
        if(F[i]){
            notprime[num++] = i;
        }
    }
}

unsigned long long int cal(unsigned long long int a,unsigned long long int b){
    unsigned long long int ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
} 

void sol(){
    s.clear();
    s.insert(1);
    for(int i = 2; i < 80000; i++){
        int maxx = ceil(64*log(2) / log(i)) - 1;
        for(int j = 0; notprime[j] <= maxx; j++){
            s.insert(cal(i, notprime[j]));
        }
    }
    for(set<unsigned long long int>::iterator it = s.begin(); it != s.end(); it++){
        printf("%llu\n", *it);
    }
}

int main(){
    init();
    sol();
}