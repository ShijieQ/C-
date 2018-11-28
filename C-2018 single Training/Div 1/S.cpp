#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 105;

int main(){
    /*
    freopen("S.in", "r", stdin);
    freopen("S.out", "w", stdout);
    */
    char a[maxn], b[maxn];
    int va[26], vb[26];
    while(cin>>a>>b){
        int flag = 1;
        memset(va, 0, sizeof(va));
        memset(vb, 0, sizeof(vb));
        for(int i = 0; i < strlen(a); i++){
            va[a[i] - 'A']++;
            vb[b[i] - 'A']++;
        }
        sort(va, va+26);
        sort(vb, vb+26);
        for(int i = 0; i < 26; i++){
            if(va[i] != vb[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
