#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#define maxn 10000+5
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        char s[maxn];
        set<int> g;
        long long int maxx = 0;
        int flag = 1, flag1 = 0;
        scanf("%s", s+1);
        int first[maxn], ending[maxn];
        memset(first, 0, sizeof(first));
        memset(ending, 0, sizeof(ending));
        if(s[1] == '0'){
            flag = 0;
        }
        for(int i = 1; i <= n; i++){
        /*    if(s[i] == '1'){
                first[i] = first[i-1]+1;
            }
            else{
                first[i] = 0;
            }*/
            int ans = 0;
            int j;
            for(j = i; s[j] == '1' && j <= n; j++){
                ans++;
            }
            if(j == n+1){
                flag1 = 1;
            }
            first[i] = ans;
            i = j;
        }/*
        for(int i = 1; i <= n; i++){
            cout<<first[i]<<endl;
        }*/
        long long int ans = 0;
        sort(first+1, first+n+1, cmp);

        for(int i = 1; i <= k; i++){
            ans += first[i];
        }
        cout<<ans<<endl;
    }
}