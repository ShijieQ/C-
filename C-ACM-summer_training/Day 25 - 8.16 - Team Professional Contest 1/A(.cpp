#include<bits/stdc++.h>
#define INF 0x7fffffff

long long gcd(long long a, long long b){
    return b ? gcd(b, a%b) : a;
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

struct point{
    long long  x, y, z;
    point(long long a, long long b, long long c):x(a), y(b), z(c){}
    point operator + (const point &other) const{
        return point(x+other.x, y+other.y, z+other.z);
    }
    point operator - (const point &other) const{
        return point(x-other.x, y-other.y, z-other.z);
    }
    point operator - () const{
        return point(-x, -y, -z);
    }
    point operator * (int p) const{
        return point(x*p, y*p, z*p);
    }
    bool operator == (const point &other) const{
        return x == other.x && y == other.y && z == other.z; 
    }
    // 两点对应的向量叉乘，即a × b;
    point operator * (const point &other) const{
        return point(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    // 两点对应的向量点乘，即a · b;
    long long dot(const point &other) const{
        return x*other.x + y*other.y + z*other.z;
    }
};

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

int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main(){
    int T;
    printf("%d\n", INF);
    scanf("%d", &T);
    for(int k = 1; k <= T; k++){
        long long x1, y1, z1, x2, y2, z2;
        long long x3, y3, z3, x4, y4, z4;
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
        scanf("%lld %lld %lld %lld %lld %lld", &x3, &y3, &z3, &x4, &y4, &z4);
/*        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        cin>>x3>>y3>>z3>>x4>>y4>>z4;*/
//        answer(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
    }
}