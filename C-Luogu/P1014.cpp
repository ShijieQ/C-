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
const int maxn = 2e5+10;

int main(){
    int n;
    cin>>n;
    int k = ceil(1.0*(sqrt(1 + 8*n) - 1)/2 - 1);
    int b = n - k*(k+1)/2;
    // cout<<"k = "<<k<<endl;
    // cout<<"b = "<<b<<endl;
    if(!(k&1)){
        cout<<(k+2-b)<<"/"<<b<<endl;
    }
    else{
        cout<<b<<"/"<<(k+2-b)<<endl;
    }
    return 0;
}