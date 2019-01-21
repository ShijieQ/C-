#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

long long int cal(long long int a){
    long long int num = 0;
    while(a){
        if(a&1){
            num++;
        }
        a >>= 1;
    }
    //cout<<"num = "<<num<<endl;
    long long int ans = 1;
    long long int temp = 2;
    while(num){
        if(num&1){
            ans = ans * temp;
        }
        temp = temp*temp;
        num >>= 1;
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long int a;
        cin>>a;
        cout<<cal(a-1)<<endl;
    }
    return 0;
}