#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 4+3;

int main(){
    int a[maxn];
    for(int i = 1; i <= 4; i++){
        cin>>a[i];
    }
    if(a[1] + a[3] == 2*a[2] && a[2] + a[4] == 2*a[3]){
        cout<<a[4] + a[2] - a[1]<<endl;
    }
    else if(a[1]*a[3] == a[2]*a[2] && a[2]*a[4] == a[3]*a[3]){
        if(!(a[4]*a[4]%a[3])){
            cout<<a[4]*a[4]/a[3]<<endl;
        }
        else{
            cout<<"42"<<endl;
        }
    }
    else{
        cout<<"42"<<endl;
    }
    system("pause");
    return 0;
}
/*
2 8 32 128 512
*/