#include<bits/stdc++.h>

const int maxn = 100000 + 100;
const unsigned long long base = 233;
char s[maxn];
char s1[maxn];
unsigned long long hash1[maxn];
unsigned long long p1[maxn];
unsigned long long hash2[maxn];
unsigned long long p2[maxn];

void init(){
    p1[0] = 1;
    hash1[0] = 0;
    int len = strlen(s + 1);
    for(int i = 1; i < maxn; i ++)
        p1[i] = p1[i-1] * base;
    for(int i = 1; i <= n; i ++)
        hash1[i] = hash1[i - 1] * base + (s[i] - 'a');
}

void gethash(){
    p2[0] = 1;
    hash2[0] = 0;
    int len = strlen(s1 + 1);
    for(int i = 1; i < maxn; i ++)
        p2[i] = p2[i-1] * base;
    for(int i = 1; i <= n; i ++)
        hash2[i] = hash2[i - 1] * base + (s1[i] - 'a');
}

unsigned long long get1(int l, int r){
    return hash1[r] - hash1[l - 1] * p1[r - l + 1];
}

unsigned long long get2(int l, int r){
    return hash2[r] - hash2[l - 1] * p2[r - l + 1];
}

int main(){
    scanf("%s", s + 1);
    init();
    int n;
    scanf("%d", &n);
    while(n--){

    }
}