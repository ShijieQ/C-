#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
    int n;
    cin>>n;
    int ans = 0;
    int val = INF;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= 100; i++){
        int temp = 0;
        for(int j = 1; j <= n; j++){
            if(abs(a[j] - i) > 1){
                temp += abs(a[j] - i) - 1;
            }
        }
        if(temp < val){
            ans = i;
            val = temp;
        }
    }
    cout<<ans<<" "<<val<<endl;
    return 0;
}