#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 4+3;

int main(){
    int a[maxn];
    cin>>a[1]>>a[2];
    int d = a[2] - a[1];
    double q = a[2]*1.0 / a[1];
    bool flag1 = 1, flag2 = 1;
    for(int i = 3; i <= 4; i++){
        cin>>a[i];
        if(flag1 && a[i] - a[i-1] != d){
            flag1 = 0;
        }
        if(flag2 && fabs(a[i]*1.0 / a[i-1] - q) > 1e-7){
            flag2 = 0;
        }
    }
    if(flag1){
        cout<<a[4] + d<<endl;
        return 0;
    }
    else if(flag2 && fabs(a[4]*q - int(a[4]*q+0.5)) < 1e-7){
        cout<<int(a[4]*q+0.5)<<endl;
        return 0;
    }
    else{
        cout<<42<<endl;
    }
    return 0;
}
/*
2 8 32 128 512
*/