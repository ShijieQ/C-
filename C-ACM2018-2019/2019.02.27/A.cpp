#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e4+10;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
    int n, t;
    cin>>n>>t;
    for(int i = 1; i <= n-1; i++){
        cin>>a[i];
    }
    bool flag = 0;
    int step = 1;
    while(step < t){
        step += a[step];
        if(step == t){
            flag = 1;
            break;
        }
    }
    cout<<(flag ? "YES":"NO")<<endl;
    return 0;
}