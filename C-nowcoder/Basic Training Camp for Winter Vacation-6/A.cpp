#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;

int main(){
    long long int n, m;
    cin>>n>>m;
    if(n > 9*m || n < 6*m){
        cout<<"jgzjgzjgz"<<endl;
    }
    else {
        cout<<max(1LL*0, 7*m - n)<<endl;
    }
    return 0;
}