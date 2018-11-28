#include<set>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000+100;
string s;
queue<string> q;
queue<string> q2;
set<string> k;
set<string> k2;
set<string> ans;
set<string>::iterator it1;
set<string>::iterator it2;

void init(){
    freopen("dictionary.in", "r", stdin);
    freopen("dictionary.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int n;
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            cin>>s;
            string s1 = s;
            int len = s.size();
            s = " " + s;
            for(int i = 1; i <= len; i++){
                string tem = s.substr(1, i);
                k.insert(tem);
                string tem1 = s.substr(i,len-i+1);
                k2.insert(tem1);
            }
            ans.insert(s1);
        }
        for(it1 = k.begin(); it1 != k.end(); it1++){
            string tem = *it1;
            q.push(tem);
        }
        for(it2 = k2.begin(); it2 != k2.end(); it2++){
            string tem = *it2;
            q2.push(tem);
        }
        int len = q2.size();
        while(!q.empty()){
            for(int i = 1; i <= len; i++){
                string tem = q.front() + q2.front();
                ans.insert(tem);
                string g = q2.front();
                q2.pop();
                q2.push(g);
            }
            q.pop();
        }
        long long int kkk = ans.size();
        cout<<kkk<<endl;
    }
}
