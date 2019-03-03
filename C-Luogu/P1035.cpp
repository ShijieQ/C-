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
const int maxn = 5e7+10;
const double lo = 1e-9;

int main(){
    int k;
    cin>>k;
    double ans = 0;
    bool flag = 1;
    for(int i = 1; i < maxn && flag; i++){
        ans += (1.0/i);
        if(ans - k >= lo){
            cout<<i<<endl;
            flag = 0;
        }
    }    
    return 0;
}