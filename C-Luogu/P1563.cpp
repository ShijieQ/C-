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

using namespace std;
const int maxn = 1e5+10;
pair<bool, string> a[maxn];

int main(){
    freopen("testdata.in", "r", stdin);
    freopen("testdata.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        cin>>a[i].first>>a[i].second;
    int pos = 0;
    for(int i = 0; i < m; i++){
        bool sta;
        int len;
        cin>>sta>>len;
        if(a[pos].first ^ sta)
            pos = (pos + len)%n;
        else
            pos = (pos - len + 1LL*maxn*n)%n;
        //cout<<"i = "<<i<<" , pos = "<<pos<<endl;
    }
    cout<<a[pos%n].second<<endl;
    return 0;
}
