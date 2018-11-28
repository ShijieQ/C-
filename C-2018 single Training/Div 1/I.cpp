#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000+10;
int a[maxn][10];

void init(){
    memset(a[0], 0, sizeof(a[0]));
    for(int i = 1; i < maxn; i++){
        for(int j = 0; j <= 9; j++){
            a[i][j] = a[i-1][j];
        }
        int tem = i;
        while(tem){
            a[i][tem%10]++;
            tem /= 10;
        }
    }
}

int main(){
    /*
    freopen("I.in", "r", stdin);
    freopen("I.out", "w", stdout);
    */
    init();
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        cout<<a[k][0];
        for(int i = 1; i <= 9; i++){
            cout<<" "<<a[k][i];
        }
        cout<<endl;
    }
}