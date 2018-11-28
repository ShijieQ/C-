#include<cmath>
#include<vector>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 105;
int a[maxn];

int gcd(int a, int b){
    return b ? gcd(b, a%b):a;
}

int scan(int a[]){
    int cnt = 0;
    string str;
    getline(cin, str);
    stringstream stream(str);
    while(stream >> a[cnt]){
        cnt++; 
    }
    return cnt;
}

int sol(int a[], int num){
    int ans = 0;
    for(int i = 0; i < num-1; i++){
        for(int j = i+1; j < num; j++){
            if(ans){
                ans = max(ans, gcd(a[i], a[j]));
            }
            else{
                ans = gcd(a[i], a[j]);
            }
        }
    }
    return ans;
}

int main(){
    /*
    freopen("V.in", "r", stdin);
    freopen("V.out", "w", stdout);*/
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i++){
        memset(a, 0, sizeof(a));
        int num = scan(a);
        printf("%d\n", sol(a, num));
    }
}
/*
3
10 20 30 40
7 5 12
125 15 25
*/

