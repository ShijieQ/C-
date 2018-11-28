#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int INF = 1e9;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int jud(int k){
    int cnt = 0;
    while(k){
        cnt += (k/5);
        k /= 5;
    }
    return cnt;
}

int sol(int a){
    long long int l = 1, r = INF, mid;
    while(l <= r){
        mid = (l+r)>>1;
        if(jud(mid) < a){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(jud(l) == a){
        return l;
    }
    else{
        return 0;
    }
}

int main(){
    init();
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        int a;
        cin>>a;
        int ans = sol(a);
        cout<<"Case "<<t<<": ";
        if(ans){
            cout<<ans<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
    }
}