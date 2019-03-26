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
queue<int> D, R;
char a[maxn];

int main(){
    int n;
    scanf("%d%s", &n, a);
    for(int i = 0; i < n; i++){
        if(a[i] == 'D'){
            D.push(i);
        }
        else{
            R.push(i);
        }
    }
    while(!D.empty() && !R.empty()){
        if(D.front() > R.front()){
            R.push(n + R.front());
            R.pop();
            D.pop();
        }
        else{
            D.push(n + D.front());
            D.pop();
            R.pop();
        }
    }
    if(D.empty()){
        cout<<"R"<<endl;
    }
    else{
        cout<<"D"<<endl;
    }
    return 0;
}