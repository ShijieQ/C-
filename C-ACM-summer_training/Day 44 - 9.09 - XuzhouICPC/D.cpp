#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6;
bool F[maxn];
int prime[maxn/10];
int num = 0;
int a[maxn/10];
int flag = 0;

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

int cal(long long int k){
    if(k == 1){
        return 1;
    }
    int cnt = 0;
    memset(a, 0, sizeof(a));
    for(int i = 0; prime[i] < k && i < num; i++){
        if(k % prime[i] == 0){
            a[prime[i]] = 0;
            while(k % prime[i] == 0){
                k /= prime[i];
                a[prime[i]]++;
            }
            if(a[prime[i]] >= 2){
                return 0;
            }
            else{
                cnt++;
            }
        }
    }
    if(k > 1 && k < 1e5){
        a[k] = 1;
        cnt++;
    }
    if(k > 1e5){
        flag = 1;
        cnt++;
    }
    return cnt&1?-1:1;
}

int main(){
    init();
    for(int i = 1; i <= 50; i++){
        cout<<cal(i)<<endl;
    }
    system("pause");
}