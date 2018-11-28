#include<bits/stdc++.h>

using namespace std;
const int maxn = 105;
priority_queue<int> q;

int main(){
    int n;
    cin>>n;
    long long int ans = 0;
    int fir;
    cin>>fir;
    for(int i = 1; i <= n-1; i++){
        int tem;
        cin>>tem;
        q.push(tem);
    }
    while(fir <= q.top()){
        ans++;
        fir++;
        int tem = q.top() - 1;
        q.pop();
        q.push(tem);
    }
    cout<<ans<<endl;
    return 0;
}