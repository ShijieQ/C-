#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Online

using namespace std;
const int maxn = 2e5+10;
char a[maxn];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", a);
        int len = strlen(a);
        sort(a, a + len);
        bool flag = 1;
        for(int i = 0; i < len; i++){
            if(a[i] != a[0] + i){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}