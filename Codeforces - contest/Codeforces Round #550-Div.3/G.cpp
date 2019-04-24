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
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int inc = -1, dec = INF, flag = 1;;
    for(int i = 1; i <= n; i++){
        if(i < n && a[i] > inc && a[i] < dec){
            if(a[i] > a[i + 1]){
                dec = a[i];
                a[i] = 1;
            }
            else if(a[i] < a[i + 1]){
                inc = a[i];
                a[i] = 0;
            }
            else{
                inc = dec = a[i];
                a[i] = 1, a[i + 1] = 0;
                i++;
            }
        }
        else if(a[i] > inc){
            inc = a[i];
            a[i] = 0;
        }
        else if(a[i] < dec){
            dec = a[i];
            a[i] = 1;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i = 1; i <= n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}