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
int day[8];

int main(){
    int ans = 0;
    for(int i = 1; i <= 7; i++){
        int a, b;
        cin>>a>>b;
        day[i] = a+b-8;
        ans = day[i] > day[ans] ? i:ans;
    }
    cout<<ans<<endl;
    return 0;
}