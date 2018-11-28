#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+10;
int a[maxn];
int vit[maxn];
int q[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        vit[a[i]] = i;
    }
    int now = 0;
    for(int i = 1; i <= n; i++){
        int tem;
        cin>>tem;
        if(vit[tem] > now){
            q[i] = vit[tem] - now;
            now = vit[tem];
        }
        else{
            q[i] = 0;
        }
    }
    cout<<q[1];
    for(int i = 2; i <= n; i++){
        cout<<" "<<q[i];
    }
    cout<<endl;
    return 0;
}