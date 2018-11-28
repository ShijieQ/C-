#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 90;
map<char, double> mp;

void init(){
    mp['C'] = 12.01;
    mp['H'] = 1.008;
    mp['O'] = 16.00;
    mp['N'] = 14.01;
}

int main(){
    /*
    freopen("H.in", "r", stdin);
    freopen("H.out", "w", stdout);
    */
    init();
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int len = s.length();
        s = " " + s;
        double ans = 0;
        for(int i = 1; i <= len; i++){
            if(mp[s[i]]){
                double tem = mp[s[i]];
                //cout<<s[i]<<"  "<<mp[s[i]];
                int num = 0;
                while(i+1 <= len && !mp[s[i+1]]){
                    num = num*10 + s[i+1]-'0';
                    i++;
                }
                if(!num){
                    num++;
                }
                //cout<<"num = "<<num<<endl;
                ans += num*tem;
            }
        }
        printf("%.3f\n", ans);
    }
}
/*
4
C
C6H5OH
NH2CH2COOH
C12H22O11
*/