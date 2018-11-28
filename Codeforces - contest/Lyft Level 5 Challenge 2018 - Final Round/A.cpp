#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

int main(){
    unsigned long long int n, x, y;
    cin>>n>>x>>y;
    if(x + y > n + 1){
        cout<<"Black"<<endl;
    }
    else {
        cout<<"White"<<endl;
    }
    return 0;
}