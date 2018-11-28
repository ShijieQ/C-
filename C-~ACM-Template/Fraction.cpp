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