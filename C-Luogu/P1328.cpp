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
const int maxn = 200+10;
bool check[][5] = {{0, 0, 1, 1, 0},
                   {1, 0, 0, 1, 0},
                   {0, 1, 0, 0, 1},
                   {0, 0, 1, 0, 1},
                   {1, 1, 0, 0, 0}};
int a[maxn], b[maxn];

int main(){
    int n, len1, len2;
    cin>>n>>len1>>len2;
    for(int i = 0; i < len1; i++){
        cin>>a[i];
    }
    for(int i = 0; i < len2; i++){
        cin>>b[i];
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        ans1 += check[a[i%len1]][b[i%len2]];
        ans2 += check[b[i%len2]][a[i%len1]];
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}