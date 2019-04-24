#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3+10;
vector<int> bot[maxn];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    string s = "", check = "";
    for(int i = 1; i <= N; i++){
        s = s + '0';
        check = check + '0';
    }
    // cout<<s<<endl;
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int temp;
        scanf("%d", &temp);
        s[temp - 1] = '1';
    }
    // cout<<s<<endl;
    for(int i = 1; i <= N; i++){
        int num;
        scanf("%d", &num);
        for(int j = 1; j <= num; j++){
            int temp;
            scanf("%d", &temp);
            bot[i-1].push_back(temp);
        }
    }
    int ans = 0;
    for(int i = 0; i < 2*N; i++){
        ans++;
        int siz = bot[i%N].size();
        for(int j = 0; j < siz; j++){
            int k = bot[i%N][j] - 1;
            s[k] = (s[k] == '0' ? '1':'0');  
        }
        // cout<<s<<endl;
        if(s == check){
            break;
        }
    }
    if(s == check){
        printf("%d\n", ans);
    }
    else{
        printf("-1\n");
    }
    return 0;
}