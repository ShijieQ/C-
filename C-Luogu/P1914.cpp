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
const int maxn = 50+5;
char str[maxn];

int main(){
    int n;
    cin>>n;
    cin>>str;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        str[i] = (str[i] - 'a' + n)%26 + 'a';
    }
    cout<<str<<endl;
    return 0;
}