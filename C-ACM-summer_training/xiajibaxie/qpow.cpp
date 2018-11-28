#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e7+5;
int p;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

long long qpow(long long a, long long b){
    long long int ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%p;
        }
        a = (a*a)%p;
        b >>= 1; 
    }
    return ans;
}

int main(){
    init();
    long long n; 
    int r;
    while(cin>>n>>p>>r){
        if(n >= 2*p){
            if(!r)
                cout<<p+1<<" "<<1<<endl;
            else
                cout<<"-1 -1"<<endl;
        }
        else if(n > p && n < 2*p){
            if(!r)
                cout<<p+1<<" "<<1<<endl;
            else{
                long long k = 1;
                for(int i = 2; i <= n; i++){
                    k = (k*i)%p;
                }
                for(int i = 1; i < p; i++){
                    if(k*i%p == r){
                        cout<<p<<" "<<i<<endl;
                        return 0;
                    }
                }
                cout<<"-1 -1"<<endl;
            }
        }
        else if(n == p){
            if(!r){
                if (n == 2) 
                    cout << -1 << " " << -1 << endl;
                else 
                    cout << 2 << " " << 1 << endl;
                return 0;
            }
            else{
                for(int i = 1; i < p; i++)  
                    if(i*(p-1)%p == r){
                        cout << p << " " << i << endl;
                        return 0;
                    }
                cout << -1 << " " << -1 << endl;
                return 0;
            }        
        }
        else if(n < p){
            if(!r)
                cout<<"-1 -1"<<endl;
            else{
                long long k = 1;
                for(int i = 2; i <= n; i++)
                    k = k*i%p;
                k = qpow(k, p-2);
                for(int i = 2; i <= n; i++){
                    long long ans = r*i%p*k%p;
                    if(ans > 0 && ans < i){
                        cout<<i<<" "<<ans<<endl;
                        return 0;
                    }
                }
                cout<<"-1 -1"<<endl;
            }
        }
    }
}
