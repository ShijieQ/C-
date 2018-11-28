#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 7;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first == b.first ? a.second < b.second:a.first < b.first;
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        pair<int, int> p[maxn];
        int flag = 0;
        if(a > b){
            p[0].first = b;
            p[0].second = a;
        }
        else{
            p[0].first = a;
            p[0].second = b;
        }
        for(int i = 1; i <= 5; i++){
            scanf("%d%d", &a, &b);
            if(a > b){
                p[i].first = b;
                p[i].second = a;
            }
            else{
                p[i].first = a;
                p[i].second = b;
            }
        }
        sort(p, p+6, cmp);
        if((p[0].first == p[1].first && p[0].second == p[1].second) && (p[2].first == p[3].first && p[2].second == p[3].second) && (p[4].first == p[5].first && p[4].second == p[5].second)){
            flag = 1;
        }
        if(p[0].first != p[2].first || p[0].second != p[4].first || p[2].second != p[4].second){
            flag = 0;
        }
        if(flag){
            cout<<"POSSIBLE"<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
}