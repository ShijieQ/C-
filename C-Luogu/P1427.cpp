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
stack<int> s;

int main(){
    int n;
    cin>>n;
    while(n){
        s.push(n);
        cin>>n;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}