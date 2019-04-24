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
const int maxn = 1e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int a[maxn];
int l, r;

int main(){
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= q; i++){
        int temp_l, temp_r;
        scanf("%d%d", &temp_l, &temp_r);
    }
    return 0;
}