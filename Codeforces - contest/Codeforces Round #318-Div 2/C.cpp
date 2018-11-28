#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

int cal(int a){
    while(!(a%2)){
        a /= 2;
    }
    while(!(a%3)){
        a /= 3;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int fir;
    cin>>fir;
    int ans = cal(fir);
    bool flag = 1;
    for(int i = 2; i <= n; i++){
        int tem;
        cin>>tem;
        if(cal(tem) != ans){
            flag = 0;
            continue;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}