#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 55;
const int INF = 0x3f3f3f3f;
string s[maxn];
vector<char> v;

bool cmp(string a, string b){
    return a < b;
}

int main(){
    /*
    freopen("M.in", "r", stdin);
    freopen("M.out", "w", stdout);
    */
    int T;
    scanf("%d", &T);
    while(T--){
        v.clear();
        int n, l;
        scanf("%d%d", &n, &l);
        v.reserve(l+1);
        for(int i = 1; i <= n; i++){
            cin>>s[i];
        }
        sort(s+1, s+n+1, cmp);
        long long int ans = 0;
        for(int i = 0; i < l; i++){
            map<char, int> mp;
            pair<char, int> p;
            p.second = -INF;
            for(int j = 1; j <= n; j++){
                mp[s[j][i]]++;
                if(mp[s[j][i]] > p.second || (mp[s[j][i]] == p.second && s[j][i] < p.first)){
                    p.first = s[j][i];
                    p.second = mp[s[j][i]];
                }
            }
            v.push_back(p.first);
            ans += (n - p.second);
        }
        for(int i = 0; i < v.size(); i++){
            cout<<v[i];
        }
        cout<<endl<<ans<<endl;
    }
}
/*
3
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA
6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA
*/