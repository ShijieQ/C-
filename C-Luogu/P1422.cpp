#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
    long long int n;
    cin>>n;
    double ans = 0;
    if(n <= 150){
        ans = 0.4463*n;
    }
    else if(n > 150 && n <= 400){
        ans = 0.4463*150 + (n-150)*0.4663;
    }
    else {
        ans = 0.4463*150 + 250*0.4663 + (n-400)*0.5663;
    }
    ans = (int)(ans*10+0.5)/10.0;
    cout<<ans<<endl;
    return 0;
}