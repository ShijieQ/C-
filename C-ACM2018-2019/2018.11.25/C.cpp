#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 20+5;

int main(){
    ios::sync_with_stdio(false);
    int m, n;
    cin>>m>>n;
    string a, b;
    cin>>a>>b;
    if((a[0] == '>' && (b[0] == 'v' || b[n-1] == '^')) || (a[0] == '<' && (b[0] == '^' || b[n-1] == 'v')) || (b[0] == 'v' && a[m-1] == '<') || (b[n-1] == 'v' && a[m-1] == '>') || (b[n-1] == '^' && a[m-1] == '<')){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}