#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;

int main() {
    int n, m;
    cin>>n>>m;
    if(min(n, m) & 1){
        cout<<"Akshat"<<endl;
    }
    else{
        cout<<"Malvika"<<endl;
    }
    return 0;
}