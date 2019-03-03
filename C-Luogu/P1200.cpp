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
const int maxn = 10;
char a[maxn], b[maxn];

int main(){
    cin>>a>>b;
    long long int a_value = 1, b_value = 1;
    for(int i = 0; a[i] != '\0'; i++){
        a_value *= (a[i] - 'A' + 1);
    }
    for(int i = 0; b[i] != '\0'; i++){
        b_value *= (b[i] - 'A' + 1);
    }
    if(a_value%47 == b_value%47){
        cout<<"GO"<<endl;
    }
    else{
        cout<<"STAY"<<endl;
    }
    return 0;
}