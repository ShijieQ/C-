#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100000 + 5;

int main(){
    int len;
    cin>>len;
    char s[maxn];
    cin>>s;
    sort(s, s+len);
    cout<<s<<endl;    
    return 0;
}