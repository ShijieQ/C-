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
const int maxn = 5000+10;
string a = "00000000000";
vector<string> vec;
int n;

void dfs(int cnt, int k){
    if(cnt == n && k == 10){
        vec.push_back(a);
        return ;
    }
    if(cnt > n){
        return ;
    }
    for(int i = 1; i <= 3; i++){
        a[k+1] += i;
        dfs(cnt+i, k+1);
        a[k+1] -= i;
    }
    return ;
}

int main(){
    cin>>n;
    if(n < 10 || n > 30){
        cout<<'0'<<endl;
        return 0;
    }
    dfs(0, 0);
    cout<<vec.size()<<endl;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 1; j <= 10; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}