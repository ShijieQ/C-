#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;

int main(){
    double x, q = 0.98;
    cin>>x;
    double ans = log(1 - x*(1 - q)/2)/log(q);
    cout<<(int)(ceil(ans))<<endl;
    return 0;
}