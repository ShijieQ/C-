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
char a[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        a[i] = '1'+i;
    }
    do{
        for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(a, a+n));
    return 0;
}