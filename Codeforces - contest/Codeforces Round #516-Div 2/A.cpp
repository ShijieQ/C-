#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    int cnt = 0;
    while(a[0]+a[1] <= a[2]){
        a[0]++;
        sort(a, a+3);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}