#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x){
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point{
    double x, y;
    Point() {}
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    Point operator-(const Point &b) const{
        return Point(x - b.x, y - b.y);
    }                                                                    //叉积
    double operator^(const Point &b) const { 
        return x * b.y - y * b.x; 
    } //点积
    double operator*(const Point &b) const { 
        return x * b.x + y * b.y; 
    } //绕原点旋转角度B（弧度值），后x,y的变化
    void transXY(double B)
    {
        double tx = x, ty = y;
        x = tx * cos(B) - ty * sin(B);
        y = tx * sin(B) + ty * cos(B);
    }
};
struct Point p[maxn];

int main(){
    int n;
    int R;
    scanf("%d%d", &n, &R);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &p[i].x, &p[i].y);
    }
}