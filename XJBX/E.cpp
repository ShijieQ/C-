#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e6 + 10;
bool vis;

int main(){
    int n;
    cin>>n;
    unsigned long long int ans = 0;
    bool ansvis = 1;
    getchar();
    for(int i = 1; i <= n; i++){
        char ch;
        ch = getchar();
        unsigned long long int temp = 0;
        if(ch != '-'){
            vis = 1;
            temp = ch - '0';
        }
        else{
            vis = 0;
        }
        ch = getchar();
        while(ch != ' ' && ch != '\n'){
            temp = temp*10 + ch - '0';
            ch = getchar();
        }
        if(i == 1){
            ans = temp;
            ansvis = vis;
        }
        else{
            if(vis && !ansvis){
                ans = temp;
                ansvis = vis;
            }
            else if(vis && ansvis){
                ans = temp > ans ? temp:ans;
            }
            else if(!vis && !ansvis){
                ans = temp < ans ? temp:ans;
            }
        }
    }
    if(!ansvis){
        cout<<"-";
    }
    cout<<ans<<endl;
    return 0;
}