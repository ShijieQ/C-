#include<bits/stdc++.h>

const int INF  = 0x3f3f3f3f;
const int Maxn = 1e7 * 2;
const int mod  = 2333333;

#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;

int pcnt = 0, prime[1300000]; 
short  mu[Maxn];           
bool vis[Maxn];

void init() {
    mu[1] = 1;
    for (int i = 2; i < Maxn; i++) {
        if (vis[i] == 0) {
            mu[i] = -1;
            prime[++pcnt] = i;
        }
        for (int j = 1; j <= pcnt && i * prime[j] < Maxn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] != 0)
                mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }

    for (int i = 2; i < Maxn; i++) mu[i] += mu[i - 1];   //  函数前缀和
}

struct Hash {
    long long key;
    int value, next;
} node[mod];
int cnt = 0, Head[mod] = {0};

void Insert(long long N, int v) {  // 记忆
    int ha = N % mod;
    node[++cnt].key = N;
    node[cnt].value = v;
    node[cnt].next = Head[ha];
    Head[ha] = cnt;
}


int M(long long N) {
    if (N < Maxn) return mu[N];
    int ha = N % mod;
    for (int i = Head[ha]; i != 0; i = node[i].next) {  
        if (node[i].key == N)   
            return node[i].value;
    }
    int  ans = 0;
    for (long long i = 2, j; i <= N; i = j + 1) {
        j = N / (N / i);   
        ans += (j - i + 1) * M(N / i);
    }
    Insert(N, 1 - ans);  
    return 1 - ans;
}

int cal(long long int k){
    if(k == 1){
        return 1;
    }
    int cnt = 0;
    int num = 0;
    for(int i = 1; prime[i] < k && i <= pcnt; i++){
        if(k % prime[i] == 0){
            num = 0;
            while(k % prime[i] == 0){
                k /= prime[i];
                num++;
            }
            if(num >= 2){
                return 0;
            }
            else{
                cnt++;
            }
        }
    }
    if(k > 1){
        cnt++;
    }
    return cnt&1?-1:1;
}

int main() {
    init();
    long long a, b;
    while (cin >> a >> b) {
        cout<<cal(b)<<endl;
        cout<<M(2)<<endl;
        cout<<M(1)<<endl;
        cout << (M(a) - M(1))*cal(b) << endl;
    }
}