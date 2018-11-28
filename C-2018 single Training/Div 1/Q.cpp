#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;

int compare(string a, string b, int n){
    int len = a.length();
    for(int i = 0; i < len; i++){
        if(a[i]-'0' + b[i]-'0' == 4){
            return -1;
        }
    }
    /*
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    */
    if(a.length() > b.length()){
        return b.length() > n ? b.length():n;
    }
    else{
        return a.length() > n ? a.length():n;
    }
}

int main(){
    string a, b;
    while(cin>>a>>b){
        int len_a = a.length();
        int len_b = b.length();
        string a1 = a, b1 = b;
        int ans = INF;
        for(int i = len_a; i < len_a+len_b; i++){
            a = a + "0";
        } 
        for(int i = 0; i <= len_a; i++){
            int k = compare(a, b, len_a);
            if(k != -1){
                ans = min(k, ans);
            }
            b = "0" + b;    
        }
        a = a1;
        b = b1;
        for(int i = len_b; i < len_a+len_b; i++){
            b = b + "0";
        } 
        for(int i = 0; i <= len_b; i++){
            int k = compare(a, b, len_b);
            if(k != -1){
                ans = min(k, ans);
            }
            a = "0" + a;    
        }
        cout<<ans<<endl;   
    }
}