#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;

int main(){
    int l1, l2, T;
    cin>>l1>>l2>>T;
    if(l1 < l2)
        swap(l1, l2);
    while(T--){
        double x, y;
        cin>>x>>y;
        double len = sqrt(x*x + y*y);
        if(len >= (l1+l2)){
            printf("%.8f\n", len - double(l1+l2));
        }
        else if(len <= l1-l2){
            printf("%.8f\n", double(l1-l2 - len));
        }
        else {
            printf("0.00000000\n");
        }
    }
    return 0;
}