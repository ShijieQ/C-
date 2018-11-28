#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 150;
map<char, int> mp;

int main(){
    /*
    freopen("T.in", "r", stdin);
    freopen("T.out", "w", stdout);
    */
    int n;
    int cas = 0;
    while(scanf("%d", &n) != EOF && n != -1){
        mp.clear();
        string a, b;
        cin>>a>>b;
        int len_a = a.length();
        int len_b = b.length();
        int cnt = 0;
        for(int i = 0; i < len_a; i++){
            if(!mp[a[i]]){
                mp[a[i]]++;
                cnt++;
            }
        }
        int len = mp.size();
        int num = 0, ans = 0;
        for(int i = 0; i < len_b; i++){
            if(mp[b[i]] == 1){
                mp[b[i]] = -2;
                ans++;
                if(ans == len){
                    break;
                }
            }
            if(!mp[b[i]]){
                mp[b[i]] = -1;
                num++;
                if(num >= 7){
                    break;
                }
            }
        }
        cout<<"Round "<< n<<endl;
        if(ans == len){
            cout<<"You win."<<endl;
        }
        if(ans < len && num < 7){
            cout<<"You chickened out."<<endl;
        }
        if(num >= 7){
            cout<<"You lose."<<endl;
        }
    }
}