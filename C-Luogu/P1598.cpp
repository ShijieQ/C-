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
const int maxn = 100+10;
const int INF = 0x3f3f3f3f;
int num[26];
int Max = -INF;
char str[maxn];

int check(){
    for(int i = 25; i >= 0; i--){
        if(!num[i]){
            return i;
        }
    }
}

int main(){
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    char ch;
    for(int i = 1; i <= 4; i++){
        gets(str);
        int len = strlen(str);
        for(int j = 0; j < len; j++){
            if(str[j] >= 'A' && str[j] <= 'Z'){
                num[str[j]-'A']++;
                Max = max(Max, num[str[j]-'A']);
            }
        }
    }
    // 使用getchar会得零分。
    // while((ch = getchar()) != EOF){
    //     if(ch >= 'A' && ch <= 'Z'){
    //         num[ch-'A']++;
    //         Max = max(Max, num[ch-'A']);
    //     }
    // }
    for(int i = 0; i <= 25; i++){
        num[i] = Max - num[i];
    }
    for(int i = 1; i <= Max; i++){
        int temp = check();
        if(num[0]){
            cout<<' ';
            num[0]--;
        }
        else{
            cout<<'*';
        }
        for(int j = 1; j <= temp; j++){
            if(num[j]){
                cout<<"  ";
                num[j]--;
            }
            else{
                cout<<" *";
            }
        }
        cout<<endl;
        for(int j = temp+1; j <= 25; j++){
            num[j]--;
        }
    }
    cout<<"A";
    for(int i = 1; i <= 25; i++){
        cout<<" "<<(char)('A'+i);
    }
    cout<<endl;
    return 0;
}