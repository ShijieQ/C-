#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

struct point{
    double x, y;
    point(double a, double b):x(a), y(b){}
    point operator + (const point &other) const{
        return point(x+other.x, y+other.y);
    }
    point operator - (const point &other) const{
        return point(x-other.x, y-other.y);
    }
    point operator - () const{
        return point(-x, -y);
    }
    point operator * (double p) const{
        return point(x*p, y*p);
    }
    bool operator == (const point &other) const{
        return x == other.x && y == other.y; 
    }
    long long dot(const point &other) const{
        return x*other.x + y*other.y;
    }
};

struct line{
    point A, B;
    line(point A, point B):A(A), B(B){}
    double leng(){
        return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
    }
};

struct angle{
    double a, b, c;
    double ang;
    angle(double a1, double b1, double c1){
        a = a1;
        b = b1;
        c = c1;
        ang = 2*acos((a*a+b*b-c*c)/(2*a*b));
    }
};

bool judge(double a, double b){
    double k = a/b;
    if(fabs(k - int(k+0.5)) < 1e-6)
        return true;
    else    
        return false;
}

int main(){
    char k[1000];
    double x1, y1, x2, y2, x3, y3;
    while(scanf("%s", k) != EOF){
        if(k[0] == 'E')
            break;
        sscanf(k, "%lf", &x1);
        scanf("%lf", &y1);
        scanf("%lf %lf %lf %lf", &x2, &y2, &x3, &y3);
//        printf("%lf %lf %lf %lf %lf %lf", x1, y1, x2, y2, x3, y3);
        struct point A(x1, y1), B(x2, y2), C(x3, y3);
        struct line AB(A,B), BC(B, C), AC(A, C);
        double ab = AB.leng();
        double ac = AC.leng();
        double bc = BC.leng();
        struct angle a(ab, ac, bc), b(ab, bc, ac), c(bc, ac, ab);
        for(int i = 3; i <= 10000; i++){
            double k = 2*3.141592653589793/i;
            if(judge(a.ang, k) && judge(b.ang, k) && judge(c.ang, k)){
                printf("%d\n", i);
                break;
            }
        }
    }
}
/*
-1385.736326 -146.954822
430.000292 -2041.361203
1162.736034 478.316025
0.000000 4147.000000
-4147.000000 0.000000
0.000000 -4147.000000
*/