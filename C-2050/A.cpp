#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;
char check[] = {'2', '0', '5', '0'};

int main() {
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        bool flag = 1;
        int len = s.length();
        if(len % 4 != 0){
            flag = 0;
        }
        else{
            for(int i = 0; i < len; i++){
                if(s[i] != check[i%4]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}