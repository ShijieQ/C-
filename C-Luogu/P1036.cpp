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
const int maxn = 20+5;
int a[maxn];
long long int cnt = 0;
int tem = 0;

bool check(int n){
    int temp = sqrt(n);
    for(int i = 2; i <= temp; i++){
        if(!(n%i)){
            return 0;
        }
    }
    return 1;
}

void dfs(int k, int step, int sum, int n){
    if(!step){
        // cout<<++tem<<endl;
        cnt += check(sum);
        return ;
    }
    for(int i = k+1; i <= n; i++){
        dfs(i, step-1, sum+a[i], n);
    }
    return ;
}

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        dfs(i, k-1, a[i], n);
    }
    cout<<cnt<<endl;
    return 0;
}