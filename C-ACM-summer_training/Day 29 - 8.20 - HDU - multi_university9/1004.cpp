//B17041016

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<string>
const int inf = 0x7f7f7f7f;
using namespace std;
/*
struct fraction{
    long long numerator;// 分子
    long long denominator;// 分母
    fraction(long long a): numerator(a), denominator(1){}
    fraction(long long a, long long b): numerator(a), denominator(b){
        long long k = gcd(numerator, denominator);
        numerator /= k;
        denominator /= k;
        if(numerator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    void simplify(){
        if(!numerator){
            return ;
        }
        long long k = gcd(numerator, denominator);
        numerator /= k;
        denominator /= k;
    }
    fraction operator - (){
        numerator = -numerator;
        denominator = -denominator;
    }
    fraction operator + (const fraction &other) {
        long long k = lcm(denominator, other.denominator);
        return fraction(numerator * (k / denominator) + other.numerator * (k / other.denominator), k);
    }
    fraction operator - (const fraction &other){
        long long k = lcm(denominator, other.denominator);
        return *this + fraction(-other.numerator, other.denominator);
    }
};
*/
long long a, b, c, aa, bb, cc, A, B, C, T, sum,sumu, mid;
inline bool scan_d(long long  &num)
{
    char in; bool IsN = false;
    in = getchar();
    if (in == EOF) return false;
    while (in != '-' && (in<'0' || in>'9')) in = getchar();
    if (in == '-') { IsN = true; num = 0; }
    else num = in - '0';
    while (in = getchar(), in >= '0'&&in <= '9') {
        num *= 10, num += in - '0';
    }
    if (IsN) num = -num;
    return true;
}

long long  gcd(long long  x, long long  y){
    return y?gcd(y,x%y):x;
}

int main() {
    cin >> T;
    while (T--) {
        scan_d(a); scan_d(b); scan_d(c); scan_d(aa); scan_d(bb); scan_d(cc);
        A = aa * (c - b);
        B = bb * (a - c);
        C = cc * (b - a);
        sum = a + b + c;
        sumu = A + B + C;
//        cout<<sum << "  " <<sumu<<endl;
        if (sumu%sum == 0) 
            cout << sumu / sum << endl;
        else {
            long long int k = gcd(sumu, sum);
//            cout<<k<<endl; 
            if(k < 0)
                k = -k;
            cout << sumu/k <<'/' << sum/k << endl;
        }
    }
    return 0;
}