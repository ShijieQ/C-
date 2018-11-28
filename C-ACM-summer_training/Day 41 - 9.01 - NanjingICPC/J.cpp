#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e7+10;
int Q[maxn];
bool F[maxn];
int num = 0;

struct node{
    int l;
    int id;
    int ans;
}a[25];

bool cmp(struct node a, struct node b){
    return a.l < b.l;
}

bool cmp2(struct node a, struct node b){
    return a.id < b.id;
}

void init(){
    int i;
    for(i = 1; i*i < maxn; i++){
        Q[i] = i*i;
    }
    num = i;

    for(i = 2; i < num; i++){
        for(int k = 1; Q[i]*k < maxn/2; k++){
            F[Q[i]*k] = 1;
        }
    }
}

int sol(int a){
    int cnt = 0;
    for(int i = 1; i*i < a; i++){
        if(a % i == 0 && !F[a/i] && !F[i]){
            cnt++;
        }
    }
    cnt *= 2;
    int tem = int(sqrt(a));
    if(tem == sqrt(a) && !F[tem]){
        cnt++;
    }
    return cnt;
}

int main(){
    init();
    int n; 
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].l);
        a[i].id = i;
    }
    sort(a+1, a+n+1, cmp);
    int ans = 0;
    for(int i = 1, k = 1; i <= a[n].l; i++){
        ans += sol(i);
        if(i == a[k].l){
            a[k].ans = ans;
            k++;
        }
    }
    sort(a+1, a+n+1, cmp2);
    for(int i = 1; i <= n; i++){
        printf("%d\n", a[i].ans);
    }
}