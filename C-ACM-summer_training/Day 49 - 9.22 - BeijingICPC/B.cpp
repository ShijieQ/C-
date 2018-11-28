#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10 + 3;
const int maxx = pow(2, 11);
string k[maxx];
map<string, int> mp;

bool compare(string ans, string a){
    if(ans.length() > a.length()){
        return false;
    }
    int len_ans = ans.length();
    int len_a = a.length();
    int i = 0, j = 0;
    while(i < len_ans && j < len_a){
        if(ans[i] == a[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(i == len_ans){
        return true;
    }
    else{
        return false;
    }
}

void add(char a, int g){
    int i;
    int n = pow(2, g-1);
    for(i = n+1; i <= 2*n; i++){
        k[i] = k[i-n] + "";
    }
    for(i = 1; i <= n; i++){
        k[i] = k[i] + a;
    }
}

void getsub(string s){
    for(int i = 1; i < maxx; i++){
        k[i] = "";
    }
    if(s.length() == 0){
        return ;
    }
    int len = s.length();
    s = " " + s;
    for(int i = 1; i <= len; i++){
        add(s[i], i);
    }
}

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF){
        mp.clear();
        string s[maxn];
        cin>>s[1];
        for (int i = 2; i <= n; i++){
            cin >> s[i];
            s[i] = s[i] + s[i];
        }
        string ans = s[1];
        int b = pow(2, ans.length());
        getsub(s[1]);
        int flag = 1;
        for(int i = 1; i <= b-1; i++){
            for(int j = 2; j <= n; j++){
                flag = compare(k[i], s[j]);
                if(!flag){
                    break;
                }
            }
            if(flag){
                mp[k[i]]++;
            }
        }
        string gg = "";
        if(mp.empty()){
            cout<<"0"<<endl;
        }
        else{
            for(auto &v : mp){
                if(gg.length() < v.first.length()){
                    gg = v.first;
                }
                else if(gg.length() == v.first.length()){
                    gg = gg < v.first ? gg:v.first;
                }
            }
            cout<<gg<<endl;
        }
    }
}