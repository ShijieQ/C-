#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    long long int a, b;
    /* I64d WA*/
    while(scanf("%lld%lld", &a, &b) != EOF){
        if(a>b)
            cout<<a-b<<endl;
        else    
            cout<<b-a<<endl;
    }
    return 0;
}