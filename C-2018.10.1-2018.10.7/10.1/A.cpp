#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long a[6];
    for(int i = 0; i < 6; i++){
        cin>>a[i];
    }
    long long ans = 0;
    ans = min(a[0], a[4]) + min(a[1], a[5]) + min(a[2], a[3]);
    cout<<ans<<endl;
    return 0;
}