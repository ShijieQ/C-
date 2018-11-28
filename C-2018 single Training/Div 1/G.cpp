#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 85;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    freopen("G.in", "r", stdin);
    freopen("G.out", "w", stdout);
    */
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'O'){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans += cnt;
        }
        cout<<ans<<endl;
    }
}
/*
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX
*/