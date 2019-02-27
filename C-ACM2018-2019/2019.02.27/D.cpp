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
    int x1, y1;
    int x2, y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        long long int a, b, c;
        cin>>a>>b>>c;
        if((-a*x1 - c)*(-a*x2 - c) < 0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}