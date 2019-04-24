#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Online

using namespace std;
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
queue<pair<bool, pair<string, int> > > a;
queue<pair<bool, pair<string, int> > > b;

void devide(bool tem, string s){
    int i = 0;
    int len = s.length();
    while(i < len){
        string temp;
        int num = 0;
        bool flag = 0;
        while(i < len && s[i] < 'A'){
            num = num*10 + s[i] - '0';
            flag = 1;
            i++;
        }
        if(flag){
            if(tem)
                a.push(make_pair(1, make_pair(temp, num)));
            else
                b.push(make_pair(1, make_pair(temp, num)));
            flag = 0;
        }
        while(i < len && s[i] >= 'A'){
            temp += s[i];
            flag = 1;
            i++;
        }
        if(flag){
            if(tem)
                a.push(make_pair(0, make_pair(temp, num)));
            else
                b.push(make_pair(0, make_pair(temp, num)));
            flag = 0;
        }
    }
}

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len = s.length();
    int i = 0;
    for(int i = 0; i < n; i++){
        string k;
        cin>>k;
        devide(1, s);
        devide(0, k);
        bool flag = 0;
        while(!a.empty() && !b.empty()){
            if(a.front().first && !b.front().first){
                cout<<"+"<<endl;
                flag = 1;
                break;
            }
            else if(!a.front().first && b.front().first){
                cout<<"-"<<endl;
                flag = 1;
                break;
            }
            else if(a.front().first && b.front().first){
                int l = a.front().second.second;
                int r = b.front().second.second;
                if(l < r){
                    cout<<"+"<<endl;
                    flag = 1;
                    break;
                }
                else if(l > r){
                    cout<<"-"<<endl;
                    flag = 1;
                    break;
                }
            }
            else {
                string l = a.front().second.first;
                string r = b.front().second.first;
                if(l < r){
                    cout<<"+"<<endl;
                    flag = 1;
                    break;
                }
                else if(l > r){
                    cout<<"-"<<endl;
                    flag = 1;
                    break;
                }
            }
            a.pop();
            b.pop();
        }
        if(!flag){
            if((a.empty() && b.empty()) || (a.empty() && !b.empty())){
                cout<<"+"<<endl;
            }
            else{
                cout<<"-"<<endl;
            }
        }
        while(!a.empty())   a.pop();
        while(!b.empty())   b.pop();
    }
    return 0;
}
/*
11 
X52Y
X
X5
X52 
X52Y
X52Y6
32
ABC
XYZ
x51y
X8Y
X222
*/