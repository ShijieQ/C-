#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 18000;
bool F[maxn];

void init(){
    F[0] = F[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!F[i]){
            for(int k = 2; i*k < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
    F[2] = 1;
}

int main(){
    init();
    int n;
    int cas = 1;
    while(scanf("%d", &n) != EOF && n > 0){
        cout<<cas++<<": ";
        if(!F[n]){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}