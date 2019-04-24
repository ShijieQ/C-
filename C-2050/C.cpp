#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;
long long int n, m, k, a, b, c;

long long int check(int k){
    if(k == 0){
        return 0;
    }
    else if(k == 1 || k == 2){
        return min(a, b);
    }
    else if(k == 3){
        return min(2*a, b);
    }
    else if(k == 4){
        return min(2*a, 2*b);
    }
    else if(k == 5){
        return min(3*a, 2*b);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){        
        cin>>n>>m>>k>>a>>b>>c;
        long long int ans = -1;
        long long int tem = (3*a <= 2*b)*3*a + (3*a > 2*b)*2*b;
        for(int i = k; i >= 0; i--){
            long long int cnt1  = ((n+i)/6)*tem + ((m+i)/6)*tem + (k - i)*c + check((n+i)%6) + check((m+i)%6);
            if(ans == -1){
                ans = cnt1;
            }
            ans = min(ans, cnt1);
        }
        cout<<ans<<endl;
    }
    return 0;
}