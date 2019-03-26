const int maxn = 1000000 + 100;
const unsigned long long base = 233;
char s[maxn];
unsigned long long hash[maxn];
unsigned long long p[maxn]

void init(){
    p[0] = 1;
    Hash[0] = 0;
    int len = strlen(s + 1);
    for(int i = 1; i < maxn; i ++)
        p[i] = p[i-1] * base;
    for(int i = 1; i <= n; i ++)
        Hash[i] = Hash[i - 1] * base + (s[i] - 'a');
}
 
unsigned long long get(int l, int r){
    return Hash[r] - Hash[l - 1] * p[r - l + 1];
}