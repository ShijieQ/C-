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

bool tree[maxn];

int main(){
    int L, M;
    cin>>L>>M;
    for(int i = 1; i <= M; i++){
        int l, r;
        cin>>l>>r;
        for(int j = l; j <= r; j++){
            tree[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i <= L; i++){
        cnt += !tree[i];
    }
    cout<<cnt<<endl;
    return 0;
}
