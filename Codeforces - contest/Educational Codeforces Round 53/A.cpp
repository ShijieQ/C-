#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000;
int a[maxn];

int main(){
    string s;
    int len;
    cin>>len>>s;
    int flag = 1;
    for(int i = 0; i+1 < len; i++){
        if(s[i] != s[i+1]){
            cout<<"YES"<<endl<<s[i]<<s[i+1]<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}