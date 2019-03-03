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
int a[15];

int main(){
    for(int i = 1; i <= 10; i++){
        cin>>a[i];
    }
    int h;
    cin>>h;
    int cnt = 0;
    for(int i = 1; i <= 10; i++){
        if(h + 30 >= a[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}