#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

int main(){
    long long int k;
    cin>>k;
    if(k & 1)
        cout<<-1<<endl;
    else 
        cout<<1<<endl;
    return 0;
}