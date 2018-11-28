#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
 
#define MAXN 100000+10
const int mod = 1e9+7;

inline int qpow(const int n, const int k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num % mod, t >>= 1) if (t & 1) ans = ans * num % mod;
    return ans;
}

inline int inv(const int num) {
    return qpow(num, mod - 2);
}

long long get(char s[]){
    int len = strlen(s);
    long long ans = 0;
    for(int i = 0; i < len; i++){
        ans = ans*10 + s[i]-'0';
    }
    return ans;
}

bool Comper(char s[], long long num)
{
	char bit[MAXN];
	int len2 = 0,len1;
	while(num)
	{
		bit[len2++] = num%10;
		num = num/10;
	}
	bit[len2] = '\0';

	len1 = strlen(s);
	if(len1 > len2)
		return true;
	else if(len1 < len2)
		return false;
	else
	{
		for(int i = 0; i < len1; i++)
		{
			if(s[i] < bit[len1-i-1])
				return false;
		}
		return true;
	}
}

long long Mod(char s[], long long mod)
{
	int len = strlen(s);
	long long ans = 0;
	for(int i = 0; i < len; i++)
	{
		ans = (ans*10 + s[i]-'0')%mod;
	}
	return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        char s[MAXN];
        scanf("%s", s);
        long long int a, ans = 1;
        if(Comper(s, mod-1)){
            int tem = Mod(s, mod-1);
            a = tem-1+mod-1;
            // cout<<a<<endl;
            ans = qpow(2, a);
        }
        else{
            a = get(s);
            ans = qpow(2, a-1);
        }
        // ans = ans*inv(2)%mod;
        if(ans < 0){
            ans += mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}