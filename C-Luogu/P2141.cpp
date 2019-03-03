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
const int maxn = 1e5+10;
bool check[maxn];
int a[105];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        check[a[i]] = 1;
    }
    int cnt = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(check[a[i]+a[j]]){
                check[a[i]+a[j]] = 0;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
