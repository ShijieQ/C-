#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 45;
char a[maxn], b[maxn];
int F[maxn];
int ans = 0;

void init(){
    F[0] = 1;
    F[1] = 2;
    for(int i = 2; i < maxn; i++){
        F[i] = F[i-1] + F[i-2];
    }
}

int cal(int a_len, int b_len){
    int a_ans = 0, b_ans = 0;
    for(int i = a_len-1, k = 0; i >= 0; i--, k++){
        if(a[i] != '0'){
            a_ans += F[k];
        }
    }
    for(int i = b_len-1, k = 0; i >= 0; i--, k++){
        if(b[i] != '0'){
            b_ans += F[k];
        }
    }
    return a_ans+b_ans
}

int main(){
    while(scanf("%s %s", a, b) != EOF){ 
        int a_len = strlen(a);
        int b_len = strlen(b);
        
    }
}