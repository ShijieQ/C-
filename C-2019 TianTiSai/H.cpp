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
string s;

int main(){
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    getchar();
    getline(cin, s);
    int len = s.length();
    if(len < n){
        for(int i = 1; i <= n-len; i++){
            cout<<ch;
        }
        cout<<s<<endl;
    }    
    else{
        for(int i = len - n; i < len; i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}