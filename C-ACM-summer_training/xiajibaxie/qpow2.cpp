#include <iostream>
using namespace std;
 
typedef long long LL;
LL n,p,r;
 
LL qpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b&1) ans = ans*a%p;
        a = a*a%p;
        b>>=1;
    }
    return ans;
}
 
 
int main(){
    cin >> n >> p >> r;
 
    if (n == p) {
        if (r == 0) {
            if (n == 2) cout << -1 << " " << -1 << endl;
            else cout << 2 << " " << 1 << endl;
            return 0;
        }
        else {
            for (LL i=1; i<p; i++)  if (i*(p-1)%p==r) {
                cout << p << " " << i << endl;
                return 0;
            }
            cout << -1 << " " << -1 << endl;
            return 0;
        }
    }
 
    if (n>=2*p) {
        if (r == 0) cout << p+1 << " " << 1 << endl; else cout << -1 << " " << -1 << endl;
        return 0;
    }
 
    if (n>p) {
        if (r == 0) cout << p+1 << " " << 1 << endl;
        else {
           LL t = 1;
           for (LL i=2; i<=n; i++) if (i!=p) t = t*i%p;
           for (LL i=1; i<p; i++) if (t*i%p==r) { cout << p << " " << i << endl; return 0; }
           cout << -1 << " " << -1 << endl;
        }
        return 0;
    }
 
    if (n<p) {
        if (r == 0) cout << -1 << " " << -1 << endl;
        else {
            LL t = 1;
            for (LL i=2; i<=n; i++) t = t*i%p;
            t =  qpow(t,p-2);
            for (LL i=2; i<=n; i++) {
                LL tmp = r*i%p*t%p;
                if (tmp>=1 && tmp<i) { cout << i << " " << tmp << endl; return 0; }
            }
            cout << -1 << " " << -1 << endl;
        }
    }
 
    return 0;
}

