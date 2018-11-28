#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e8+10000+100;
bool F[maxn];
pair<int, int> p[10000+10];

int fun(int a){
    return a*a + a + 41;
}

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
    
    p[0].first = p[0].second = 1;
    for(int i = 1; i <= 10000; i++){
        if(!F[fun(i)]){
            p[i].first = p[i-1].first + 1;
            p[i].second = p[i-1].second + 1;
        }
        else{
            p[i].first = p[i-1].first;
            p[i].second = p[i-1].second + 1;
        }
    }
}

int main(){
    init();
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        double ans = 1;
        if(!a){
            ans = 1.0 * p[b].first / p[b].second;
        }
        else{
            ans = 1.0 * (p[b].first - p[a-1].first) / (p[b].second - p[a-1].second);
        }
        printf("%.2lf\n", ans*100+1e-8);// must add 1e-8...

    }
}
/*
0 39
0 40
39 40
*/