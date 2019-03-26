const int maxn = 10000+10;
const int mod = 9901;
const int INF = 0x3f3f3f3f;
// init();
// F[maxn]存储筛法状态，prime[maxn]存储素数，num存储素数个数
bool F[maxn];
int prime[maxn/10];
int num = 0;
// cal(long long int a);
// 存储分解定理所分解出的素数及其幂次，fac_num存储个数
pair<long long int, long long int> fac[maxn/10];
int fac_num = 0;

// 快速幂
// 时间复杂度：O(logn)
long long int qpow(long long int a, long long int b){
    long long int ans = 1;
    while(b){
        if(b&1){
            ans = ans*a%mod;
        }
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

// 费马小定理求解逆元 
// 时间复杂度：O(logn)
// 前置条件：qpow(long long int a, long long int b); 
//          mod为素数;
long long int inv(long long int a){
    return qpow(a, mod - 2)%mod;
}

// 逆元线性筛求解1 ~ maxn逆元
// 时间复杂度：O(n)
int inv[maxn];  
void getinv(){
    inv[1] = 1;  
    for(int i = 2; i < maxn; i++)  
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}

// 线性筛法求解1 ~ maxn的所有素数
// 时间复杂度：O(nlogn)
// 前置条件：mod为素数
void init(){
    F[0] = F[1] = 1;
    for(int i = 2 ; i < maxn; i++){
        if(!F[i]){
            prime[num++] = i;
            for(int k = 2; k*i < maxn; k++){
                F[i*k] = 1;
            }
        }
    }
}

// 唯一分解定理，化a = p1^k1 * p2^k2 * p3^k3 * ... * pn^kn(pi为素数)
// 时间复杂度：O(logn)
// 前置条件：init();
void cal(long long a){
    fac_num = 0;
    for(int i = 0; prime[i] < a && i < num; i++){
        int cnt = 0;
        if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                a /= prime[i];
                cnt++;
            }
            fac[++fac_num].first = prime[i];
            fac[fac_num].second = cnt;
        }
    }
    if(a != 1){
        fac[++fac_num].first = a;
        fac[fac_num].second = 1;
    }
}

