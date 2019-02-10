#include<bits/stdc++.h>

using namespace std;

int fun(int x){
    return x & -x;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        cout<<fun(k)<<endl;
    }
    return 0;
}