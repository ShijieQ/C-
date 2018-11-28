#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;    
const int INF = 2e9+100;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
}
    
long long int exgcd(long long int a, long long int b, long long int &x, long long int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    long long int t = exgcd(b, a%b, x, y);
    long long int tem = x;
    x = y;
    y = tem - a/b*y;
    return t;
}

int main(){
    init();
    long long int x, y, m, n, l;
    cin>>x>>y>>m>>n>>l;
    if(m == n){
        cout<<"Impossible"<<endl;
    }
    else{
        long long int o, p;
        if(m < n){
            swap(m, n);
            swap(x, y);
        }
        long long int c = y-x;
        long long int tem = m-n;
        long long int d = exgcd(tem, l, o, p);
        if(c%d){
            cout<<"Impossible"<<endl;
        }
        else{
            long long int ans = ((o*(c/d))%(l/d) + (l/d))%(l/d);
            cout<<ans<<endl;
        }
    }
}