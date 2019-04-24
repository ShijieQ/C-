#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e4+10;
long long int fir[maxn];

void init(){
    fir[1] = 1;
    for(int i = 2; i < maxn; i++){
        fir[i] = fir[i - 1] + 2*(i-1) - 1;
    }
}

int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        int l, r;
        int l_lin, r_lin;
        scanf("%d%d", &l, &r);
        for(int i = 1; i < maxn; i++){
            if(l < fir[i]){
                l_lin = i - 1;
                break;
            }
        }
        for(int i = 1; i < maxn; i++){
            if(r < fir[i]){
                r_lin = i - 1;
                break;
            }
        }
        
    }
}