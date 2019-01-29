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
struct node{
    long long int spend;
    long long int value;
    long long int pain;
    bool operator < (const struct node &n1){
        return spend*n1.value == n1.spend*value ? spend < n1.spend : spend*n1.value < n1.spend*value;
    }
} p[maxn];

int main(){
    int n;
    cin>>n;
    long long int cnt = 0;
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin>>a>>b;
        p[i].spend = a;
        p[i].value = b;
        cnt += b;
    }
    for(int i = 1; i <= n; i++){
        p[i].pain = cnt - p[i].value;
    }
    sort(p+1, p+n+1);
    p[0].value = 0;
    long long int k = 0;
    for(int i = 1; i <= n; i++){
        k += p[i-1].value;
        ans += (p[i].pain - k)*p[i].spend;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}