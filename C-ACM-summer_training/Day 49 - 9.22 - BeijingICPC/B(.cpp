#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 11;
vector<string> vec;

void getsub(string s, int i, string sub){
    if(i == s.length()){
        vec.push_back(sub);
        return ;
    }
    else{
        getsub(s, i+1, sub+s[i]);
        getsub(s, i+1, sub);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        string s[maxn];
        cin>>s[1];
        for(int i = 2; i <= n; i++){
            cin>>s[i];
        }
        vec.reserve((int)pow(2, s[1].length()) + 1);
        getsub(s[1], 0, "");
        for(int i = 0; i < vec.size(); i++){
            cout<<vec[i]<<endl;
        }
    }
}