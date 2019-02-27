#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e4+10;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans1 = max(3*a/10, a - a*c/250);
    int ans2 = max(3*b/10, b - b*d/250);
    if(ans1 > ans2){
        cout<<"Misha"<<endl;
    }
    else if(ans1 < ans2){
        cout<<"Vasya"<<endl;
    }
    else {
        cout<<"Tie"<<endl;
    }
    return 0;
}