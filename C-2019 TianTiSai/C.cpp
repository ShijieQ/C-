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
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
int F[] = {1, 2, 3, 4, 5, 6, 7};

int main(){
    int n;
    cin>>n;
    cout<<F[(n-1+2)%7]<<endl;
    return 0;
}