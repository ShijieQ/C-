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
const int maxn = 3e5+10;
char a[maxn];

int main(){
    cin>>a;
    int len = strlen(a);
    int ans = 0;
    for(int i = 0, k = 0; i < len-1; i++){
        ans += (a[i] != '-' ? (a[i]-'0')*(++k):0);
    }
    ans %= 11;
    if(ans == a[len-1] - '0' || (ans == 10 && a[len-1] == 'X')){
        cout<<"Right"<<endl;
    }
    else{
        a[len-1] = ans + '0';
        if(ans == 10){
            a[len-1] = 'X';
        }
        cout<<a<<endl;
    }
    return 0;
}