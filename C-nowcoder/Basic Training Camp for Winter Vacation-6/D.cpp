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
const int INF = 0x3f3f3f3f;

int main(){
    int n;
    cin>>n;
    long long int ans = 0;
    int flag = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        if(!temp){
            flag = 0;
        }
        ans += (temp+flag)/2;
        if((temp+flag) & 1){
            flag = 1;
        }
        else {
            flag = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
