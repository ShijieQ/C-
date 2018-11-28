#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5;
int l;
pair<int, int> p;

void compare(int a[], int b[]){
    p.first = 0;
    p.second = 0;
    int cnt = 0;
    for(int i = 1; i <= l; i++){
        if(a[i] == b[i]){
            cnt++;
            a[i] = b[i] = 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= l; i++){
        if(!a[i]){
            continue;
        }
        for(int j = 1; j <= l; j++){
            if(!b[j]){
                continue;
            }
            if(a[i] == b[j]){
                ans++;
                a[i] = b[j] = 0;
                break;
            }
        }
    }
    p.first = cnt;
    p.second = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    */
    int cas = 0;
    while(cin>>l && l != 0){
        cout<<"Game "<< ++cas<<":"<<endl;
        int ans[maxn], tem[maxn];
        for(int i = 1; i <= l; i++){
            cin>>ans[i];
        }
        int k[maxn];
        for(int i = 1; i <= l; i++){
            cin>>k[i];
        }
        while(k[1] != 0){
            for(int i = 1; i <= l; i++){
                tem[i] = ans[i];
            }
            compare(tem, k);
            cout<<"    ("<<p.first<<","<<p.second<<")"<<endl;
            for(int i = 1; i <= l; i++){
                cin>>k[i];
            }
        }
    }
}