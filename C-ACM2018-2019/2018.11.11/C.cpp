#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+15;
pair<pair<int, int>, int> p[maxn];

bool cmp(pair<pair<int, int>, int>)

int main(){
    int n;
    scanf("%d", &n);
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i].first.first);
        p[i].first.second = i;
        p[i].second = -1;
    }
    sort(p+1, p+n+1, cmp);

}