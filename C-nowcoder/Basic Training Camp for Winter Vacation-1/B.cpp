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
int a[maxn];
int b[5];
int c[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]]++;
    }
    sort(a, a+n+1);
    long long int ans = 0;
    int l = 0, r = n;
    while(l < r){
        ans += (a[r] - a[l])*(a[r] - a[l]);
        l++;
        if(l >= r){
            break;
        }
        ans += (a[l] - a[r])*(a[l] - a[r]);
        r--;
    }
    cout<<ans<<endl;
    return 0;
}