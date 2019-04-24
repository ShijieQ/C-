#include<bits/stdc++.h>

using namespace std;
const int maxn = 55;
int mp[maxn][maxn];

void update(int l, int r){
    for(int i = 0; i < maxn; i++){
        mp[l][i] = mp[i][r] = 1;
    }
    for(int i = 0; r + i < maxn && l + i <maxn; i++){
        mp[r + i] = mp[l + i] = 1;
    }
    for(int i = 0; r + i < maxn && l - i < maxn && l - i >= 0; i++){
        mp[r + i] = mp[l - i] = 1;
    }
    for(int i = 0; r - i < maxn && l - i < maxn && l - i >= 0 && r - i >= 0; i++){
        mp[r - i] = mp[l - i] = 1;
    }
}

int main(){
    int N;
    cin>>N;
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        int l, r;
        cin>>l>>r;
        if(!mp[l][r]){
            update(l, r);
            cnt++;
        }
    }
}