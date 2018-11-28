#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 50+5;
char a[maxn][12];
int num[i];
int l = 0, r = 0;

int main(){
    int r, num;
    scanf("%d%d", &r, &num);
    getchar();
    for(int i = 1; i <= r+3; i++){
        num[i] = 0;
        for(int j = 1; j <= 11; j++){
            scanf("%c", &a[i][j]);
            if(a[i][j] == '-')
                num[i]++;
            if(a[i][j] == '#'){
                if(i > 6)
                    r++;
                if(i < 6)
                    l++;
            }

        }   

        getchar();
    }
    
}