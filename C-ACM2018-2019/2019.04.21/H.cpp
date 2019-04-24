#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;

int main(){
    int n;
    scanf("%d", &n);
    string ans = "";
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        int lens = s.length(), lenans = ans.length();
        if(lens > lenans || (lens == lenans && s < ans)){
            ans = s;
        }
    }
    cout<<ans<<endl;
    return 0;
}