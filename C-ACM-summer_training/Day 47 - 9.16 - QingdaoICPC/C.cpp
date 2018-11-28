#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
const int mod = 256;
int a[maxn][256];

struct node{
    char s[5];
    int a, qu;
}q[maxn];

int r = 0;
int n = 0;

bool run(int k){
    memset(a, 0, sizeof(a));
    while(k <= n){
        a[k][r]++;
        if(a[k][r] > 1){
            return false;
        }
        if(!strcmp(q[k].s, "add")){
            r = (r+q[k].a)%mod;
        }
        if(!strcmp(q[k].s, "beq")){
            if(q[k].a == r){
                k = q[k].qu;
                continue;
            }
        }
        if(!strcmp(q[k].s, "bne")){
            if(q[k].a != r){
                k = q[k].qu;
                continue;
            }
        }
        if(!strcmp(q[k].s, "blt")){
            if(r < q[k].a){
                k = q[k].qu;
                continue;
            }
        }
        if(!strcmp(q[k].s, "bgt")){
            if(r > q[k].a){
                k = q[k].qu;
                continue;
            }
        }
        k++;
    }
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        r = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            char tem[5];
            scanf("%s", tem);
            strcpy(q[i].s, tem);
            if(!strcmp(tem, "add")){
                scanf("%d", &q[i].a);
                q[i].qu = 0;
            }
            else{
                scanf("%d%d", &q[i].a, &q[i].qu);
            }
        }
        if(run(1)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
