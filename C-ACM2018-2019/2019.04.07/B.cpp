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
const int maxn = 2e5+10;
char s[maxn];

long long int solve(long long int k){
    while(k >= 10){
        long long int temp = 0;
        while(k){
            temp += k%10;
            k /= 10;
            // cout<<temp<<endl;
        }
        k = temp;
    }
    return k;
}


int main(){
    while(scanf("%s", s) != EOF){
        long long int k = 0;
        int len = strlen(s);
        for(int i = 0; i < len; i++){
            k += s[i] - '0';
        }
        if(!k)  return 0;
        cout<<solve(k)<<endl;
    }    
    return 0;
}