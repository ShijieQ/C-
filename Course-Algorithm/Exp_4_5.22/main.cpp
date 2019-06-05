#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6+100;

class RSA {
private:
    bool isNotPrime[maxn];  // 素数检查标记数组
    int prime[maxn/10];     // 素数存储数组
    int num = 0;            // 素数数量
    long long int N;        // N = p*q
    long long int p, q;     // 两个大素数
    long long int sig;      // sig = (p - 1)*(q - 1)
    long long int e;        // gcd(e, sig) = 1
    long long int d;        // d = (e^-1)%sig

public:
    // 求a, b的最大公因数
    long long int gcd(long long int a, long long int b);
    void GetPrime();  // 获取1 ~ maxn内的素数
    void SetPQ();     
    long long int SetE(); 
    long long int GetN();
    long long int GetE();
    long long int GetD();
    long long int GetSig();
    long long int GetC(long long int M);
    long long int GetM_(long long int C);
    // 使用扩展欧几里得算法求解求模逆元
    long long int exgcd(long long int a, long long int b, long long int &x, long long int &y);
    long long int GetInv(int a,int mod);
    // 快速幂求模运算
    long long int qpow(long long int a, long long int b, long long int mod);
};

long long int RSA::gcd(long long int a, long long int b) {
    return b == 0 ? a:gcd(b, a%b);
}

void RSA::GetPrime() {
    isNotPrime[0] = isNotPrime[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!isNotPrime[i]) {
            prime[num++] = i;
            for (int k = 2; i*k < maxn; k++) {
                isNotPrime[i*k] = 1;
            }
        }
    }
}

void RSA::SetPQ() {
    long long int p_, q_;
    cout<<"Please input p, q : ";
    cin>>p_>>q_;
    while (isNotPrime[p_] || isNotPrime[q_]) {
        cout<<"NotPrime, Please input again : ";
        cin>>p_>>q_;
    }
    p = p_, q = q_;
    return ;
}

long long int RSA::GetN() {
    N = p*q;
    return p*q;
}

long long int RSA::GetE() {
    return e;
}

long long int RSA::GetSig() {
    sig = (p - 1)*(q - 1);
    return sig;
}

long long int RSA::exgcd(long long int a, long long int b, long long int &x, long long int &y) {
    if(b == 0) {
        x = 1,y = 0;
        return a;
    }
    long long int ret = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}

long long int RSA::GetInv(int a,int mod) {
    long long int x, y;
    long long int d = exgcd(a, mod, x, y);
    return d == 1 ? (x%mod + mod)%mod : -1;
}

long long int RSA::qpow(long long int a, long long int b, long long int mod) {
    long long int ans = 1;
    a = a%mod;
    while (b) {
        if (b & 1) {
            ans = ans*a%mod;
        }
        b >>= 1;
        a = a*a%mod;
    }
    return ans%mod;
}

long long int RSA::GetD() {
    d = GetInv(e, sig);
    return d;
}

long long int RSA::SetE() {
    long long int E;
    cout<<"Please input e : ";
    cin>>E;
    while (gcd(E, sig) != 1) {
        cout<<"NotCoprime, Please input again : ";
        cin>>E;
    }
    e = E;
    return e;
}

long long int RSA::GetC(long long int M) {
    return qpow(M, e, N);
}

long long int RSA::GetM_(long long int C) {
    return qpow(C, d, N);
}

int main() {
    long long int M, C, M_;
    RSA test;
    test.GetPrime();
    test.SetPQ();
    test.SetE();
    test.GetSig();
    cout<<"n = "<<test.GetN()<<", e = "<<test.GetE()<<endl;
    cout<<"d = "<<test.GetD()<<endl;
    cout<<"encryption : "<<endl;
    cout<<"Please input the M : ";
    cin>>M;
    cout<<"After encryption, Get C = ";
    C = test.GetC(M);
    cout<<C<<endl;
    cout<<"After decryption, Get M' = ";
    M_ = test.GetM_(C);
    cout<<M_<<endl;
    return 0;
}