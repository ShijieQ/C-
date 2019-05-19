#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 6;
int a[maxn][maxn];

void solve(){
    int count = 1;
    int i = 0, j = 0;
    a[i][j] = count;
    while(count < maxn*maxn){
        while(j+1 < maxn && !a[i][j+1]){
            a[i][++j] = ++count;
        }
        while(i+1 < maxn && !a[i+1][j]){
            a[++i][j] = ++count;
        }
        while(j-1 >= 0 && !a[i][j-1]){
            a[i][--j] = ++count;
        }
        while(i-1 >= 0 && !a[i-1][j]){
            a[--i][j] = ++count;
        }
    }
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            printf("%2d ", a[i][j]);
        }
        cout<<endl;
    }
}

int main(){
    solve();
    return 0;
}