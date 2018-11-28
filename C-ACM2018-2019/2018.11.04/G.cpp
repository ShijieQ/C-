#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+5;
char s1[maxn], s2[maxn];

int main(){
    cin>>s1>>s2;
    int len = strlen(s1);
    int cnt = 0;
    for(int i = 0; i < len; i++){
        if(s1[i] == '0' && s2[i] == '0' && (i+1 < len && s1[i+1] == '0')){
            cnt++;
            s1[i] = 'X';
            s1[i+1] = 'X';
            s2[i] = 'X';
        }
        if(s1[i] == '0' && s2[i] == '0' && (i+1 < len && s2[i+1] == '0')){
            cnt++;
            s1[i] = 'X';
            s2[i] = 'X';
            s2[i+1] = 'X';
        }
        if(s1[i] == '0' && (i+1 < len && s1[i+1] == '0' && s2[i+1] == '0')){
            cnt++;
            s1[i] = 'X';
            s1[i+1] = 'X';
            s2[i+1] = 'X';
        }
        if(s2[i] == '0' && (i+1 < len && s2[i+1] == '0' && s1[i+1] == '0')){
            cnt++;
            s2[i] = 'X';
            s2[i+1] = 'X';
            s1[i+1] = 'X';
        }
    }
    cout<<cnt<<endl;
    return 0;
}