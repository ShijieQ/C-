#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e6+10;
int ans[maxn];
int ask[250];

void init(){
    int temp = sqrt(maxn);
    for(int i = 1; i <= temp; i++){
        for(int j = i+1; j*i < maxn; j++){
            ans[i*j] += 2;
        }
        ans[i*i]++;
    }
    for(int i = 1; i <= 1000000; i++){
        if(!ask[ans[i]]){
            ask[ans[i]] = i;
        }
    }
}

int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d", &n);
        if(n > 240){
            cout<<"-1"<<endl;
            continue;
        }
        if(!ask[n]){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ask[n]<<endl;
    }
    return 0;
}