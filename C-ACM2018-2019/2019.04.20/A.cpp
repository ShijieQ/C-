#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000000000+10;
const int mod = 9901;
const int INF = 0x3f3f3f3f;


int main(){
    //for(int i = 2; i < maxn; i++){
        int i = 33550336;
        long long int ans = 0;
        for(int j = 1; j*j <= i; j++){
            if(i % j == 0){
                ans += j;
                if(i/j != j && j != 1){
                    ans += i/j;
                }
            }
        }
        if(ans == i){
            cout<<i<<endl;
        }
    //}33550336
    return 0;
}