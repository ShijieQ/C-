#include<map>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5;
map<pair<int, int>, int> mp;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int a;
        scanf("%d", &a);
        for(int i = 1; i <= a; i++){
            pair<int, int> p;
            scanf("%d%d", &p.first, &p.second);
            mp[p]++;
        }
    
    }
}