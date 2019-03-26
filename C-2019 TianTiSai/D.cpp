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
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;

int main(){
    int N;
    cin>>N;
    while(N--){
        string name;
        int fir, sec;
        cin>>name>>fir>>sec;
        if((fir < 15 || fir > 20) || (sec < 50 || sec > 70)){
            cout<<name<<endl;
        }
    }
    return 0;
}