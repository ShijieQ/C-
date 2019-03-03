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
const int maxn = 100+5;
int a[maxn];
int ans[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                ans[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}