#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;

int main(){
    int T;
    cin>>T;
    while(T--){
        double p, q;
        cin>>p>>q;
        int k = floor(p/q);
        if(p/q - k <= 1e-9){
            k--;
        }
        cout<<k<<endl;
    }
    return 0;
}