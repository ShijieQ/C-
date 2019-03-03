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
int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int a, b, c;

bool check(){
    a = num[0]*100 + num[1]*10 + num[2];
    b = num[3]*100 + num[4]*10 + num[5];
    c = num[6]*100 + num[7]*10 + num[8];
    return (a*2 == b) && (a*3 == c);
}

int main(){
    do{
        if(check()){
            cout<<a<<" "<<b<<" "<<c<<endl;        
        }
    }while(next_permutation(num, num+9));
    return 0;
}