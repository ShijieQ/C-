#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e5+10;
int a[maxn], b[maxn];
int ans = 1, k = 1;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[i+1] = 2*a[i];
        // cout<<a[i]<<"  "<<b[i]<<endl;
    }
    for(int i = 1; i <= n; i++){
        if(b[i] >= a[i]){
            k++;
            if(ans < k){
                ans = k;
            }
        }
        else {
            k = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}