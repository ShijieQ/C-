#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 100;
const int INF = 0x3f3f3f3f;
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
    } 
    double operator^(const Point &b) const { 
        return x * b.y - y * b.x; 
    } 
    double operator*(const Point &b) const { 
        return x * b.x + y * b.y; 
    } 
    void transXY(double B)
    {
        double tx = x, ty = y;
        x = tx * cos(B) - ty * sin(B);
        y = tx * sin(B) + ty * cos(B);
    }
}p[maxn];

double dist(Point a,Point b) {     
    return sqrt((a-b)*(a-b)); 
}

struct Line {  
    Point s,e;  
    Line(){}  
    Line(Point _s,Point _e){   
        s = _s;e = _e;  
    }       
    pair<int,Point> operator &(const Line &b)const{         
        Point res = s;         
        if(sgn((s-e)^(b.s-b.e)) == 0){             
            if(sgn((s-b.e)^(b.s-b.e)) == 0)                 
                return make_pair(0,res);             
            else 
                return make_pair(1,res);         
        }         
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));         
        res.x += (e.x-s.x)*t;         
        res.y += (e.y-s.y)*t;         
        return make_pair(2,res);     
    } 
}l[maxn/10];

double dis(Point P, Line L){
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    if (t >= 0 && t <= 1){
        result.x = L.s.x + (L.e.x - L.s.x) * t;
        result.y = L.s.y + (L.e.y - L.s.y) * t;
    }
    else{
        if (dist(P, L.s) < dist(P, L.e))
            result = L.s;
        else
            result = L.e;
    }
    return dist(P, result);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
        struct Point c(x1, y1), d(x2, y2);
        if(x1 > x2){
            l[i].s = c;
            l[i].e = d;
        }
        else{
            l[i].s = d;
            l[i].e = c;
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        double maii = INF;
        int id = 1;
        struct Point tem(x, y);
        for(int j = 1; j <= n; j++){
            double diss = dis(tem, l[j]);
            if(diss < maii){
                id = j;
                maii = diss;
            }
        }
        cout<<id<<endl;
    }
}