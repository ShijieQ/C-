#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000;
bool F[maxn];
int prime[maxn];
int num = 0;

int gcd(int a, int b){
    return b ? gcd(b, a%b):a;
}

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

int cal(int a){
    int ans = 0;
    for(int i = 1; prime[i] < a && i < num; i++){
        int cnt = 0;
        if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
        }
    }

}