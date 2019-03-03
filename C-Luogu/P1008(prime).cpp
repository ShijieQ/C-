#include<set>
#include<map>
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

bool check(int k){
    set<int> s;
    int a = 2*k, b = 3*k;
    if(a >= 999 || b >= 999){
        return 0;
    }
    while(k){
        if(k%10 == 0){
            return 0;
        }
        s.insert(k%10);
        k /= 10;
    }
    while(a){
        if(a%10 == 0){
            return 0;
        }
        s.insert(a%10);
        a /= 10;
    }
    while(b){
        if(b%10 == 0){
            return 0;
        }
        s.insert(b%10);
        b /= 10;
    }
    return s.size() == 9;
}

int main(){
    for(int i = 102; i <= 334; i++){
        if(check(i)){
            cout<<i<<" "<<i*2<<" "<<i*3<<endl;
        }
    }
    return 0;
}