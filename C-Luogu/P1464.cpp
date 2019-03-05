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

using namespace std;
const int maxn = 20+5;
long long int ans[maxn][maxn][maxn];

void init(){
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            ans[0][i][j] = 1;
        }
    }
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            ans[i][0][j] = 1;
        }
    }
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            ans[i][j][0] = 1;
        }
    }
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < maxn; j++){
            for(int k = 1; k < maxn; k++){
                if(i < j && j < k){
                    ans[i][j][k] = ans[i][j][k - 1] + ans[i][j - 1][k - 1] - ans[i][j - 1][k];
                }
                else{
                    ans[i][j][k] = ans[i - 1][j][k] + ans[i - 1][j - 1][k] + ans[i - 1][j][k - 1] - ans[i - 1][j - 1][k - 1];
                }
            }
        }
    }
}

int main(){
    init();
    long long int a, b, c;
    cin>>a>>b>>c;
    while(a != -1 || b != -1 || c != -1){
        if(a <= 0 || b <= 0 || c <= 0){
            printf("w(%lld, %lld, %lld) = 1\n", a, b, c);
        }
        else if(a > 20 || b > 20 || c > 20){
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans[20][20][20]);
        }
        else {
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans[a][b][c]);
        }
        cin>>a>>b>>c;
    }
    return 0;
}