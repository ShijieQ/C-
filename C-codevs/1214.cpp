#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+5;
pair<int, int> p[maxn];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int tema, temb;
        scanf("%d%d", &tema, &temb);
        if(tema > temb)
            swap(tema, temb);
        p[i].first = tema;
        p[i].second = temb;
    }
    int j = 1;
    int cnt = 1;
    sort(p+1, p+n+1, cmp);
    for(int i = 1; i <= n; i++){
        if(p[i].first >= p[j].second){
            cnt++;
            j = i;
        }
    }
    cout<<cnt<<endl;
    return 0;
}