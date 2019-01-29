#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
const double pi = 3.141592653589;

int main(){
    int f1, f2, a;
    cin>>f1>>f2>>a;
    double ans = sqrt(f1*f1 + f2*f2 + 2*f1*f2*cos(a*pi/180));
    printf("%.10f\n", ans);
    return 0;
}