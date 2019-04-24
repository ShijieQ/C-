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
int a[maxn];
vector<int> l;
vector<int> r;

int main(){
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);  
    int n;
    cin>>n;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        int lend = l.size(), rend = r.size();
        if(!rend|| r[rend - 1] != a[i]){
            r.push_back(a[i]);
        }
        else if(!lend || l[lend - 1] != a[i]){
            l.push_back(a[i]);
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag){
        reverse(r.begin(), r.end());
        cout<<"YES"<<endl;
        int lsize = l.size(), rsize = r.size();
        cout<<lsize<<endl;
        for(int i = 0; i < lsize; i++){
            cout<<l[i]<<" ";
        }
        cout<<endl;
        cout<<rsize<<endl;
        for(int i = 0; i < rsize; i++){
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}