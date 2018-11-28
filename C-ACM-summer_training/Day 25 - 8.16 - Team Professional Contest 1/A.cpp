#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

long long gcd(long long m, long long n ) 
{
    if( m == 0 || n == 0) 
        return -1;  
    long long r = m % n;
    if( 0 == r ) 
        return n;
    else 
        return gcd( n, r );
}

void answer(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2, long long x3, long long y3, long long z3, long long x4, long long y4, long long z4){
    long long ux = x2 - x1;
    long long uy = y2 - y1;
    long long uz = z2 - z1;

    long long vx = x4 - x3;
    long long vy = y4 - y3;
    long long vz = z4 - z3;

    long long wx = x1 - x3;
    long long wy = y1 - y3;
    long long wz = z1 - z3;

    long long a = (ux * ux + uy * uy + uz * uz); 
    long long b = (ux * vx + uy * vy + uz * vz); 
    long long c = (vx * vx + vy * vy + vz * vz); 
    long long d = (ux * wx + uy * wy + uz * wz); 
    long long e = (vx * wx + vy * wy + vz * wz); 
    long long dt = a * c - b * b;

    long long sd = dt;
    long long td = dt;

    long long sn = 0;
    long long tn = 0;

    if (dt == 0){
        sn = 0;    
        sd = 1;  
        tn = e; 
        td = c;
    }else{
        sn = (b * e - c * d);
        tn = (a * e - b * d);
        if (sn < 0){
            sn = 0;
            tn = e;
            td = c;
        }else if (sn > sd){
            sn = sd;
            tn = e + b; 
            td = c;
        }
    }
    if (tn < 0){
        tn = 0;
        if (-d < 0) 
            sn = 0;
        else if (-d > a) 
            sn = sd;
        else{
            sn = -d;
            sd = a;
        }
    }
    else if (tn > td){
        tn = td;
        if ((-d + b) < 0)
            sn = 0;
        else if ((-d + b) > a)
            sn = sd;
        else{
            sn = (-d + b);
            sd = a;
        }
    }
    long long sc = 0;
    long long tc = 0;
    if (sd == 0)
        sc = 0;
    else
        sc = sn / sd;
    if (td == 0)
        tc = 0;
    else
        tc = tn / td;
    long long fenzi = (wx*sd*td + sn*ux*td - tn*vx*sd)*(wx*sd*td + sn*ux*td - tn*vx*sd) + (wy*sd*td + sn*uy*td - tn*vy*sd)*(wy*sd*td + sn*uy*td - tn*vy*sd) + (wz*sd*td + sn*uz*td - tn*vz*sd)*(wz*sd*td + sn*uz*td - tn*vz*sd);
    long long fenmu = (sd*td)*(sd*td);
/*    long long dx = wx + (sc * ux) - (tc * vx);
    long long dy = wy + (sc * uy) - (tc * vy);
    long long dz = wz + (sc * uz) - (tc * vz); */
//    return dx * dx + dy * dy + dz * dz;
/*
    cout<<fenzi<<endl;
    cout<<fenmu<<endl;
    */
    long long k = gcd(fenzi, fenmu);
    if(k == -1){
        cout<<"0 1"<<endl;
    }
    else{
        cout<<fenzi/k<<" "<<fenmu/k<<endl;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int k = 1; k <= T; k++){
        long long x1, y1, z1, x2, y2, z2;
        long long x3, y3, z3, x4, y4, z4;
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
        scanf("%lld %lld %lld %lld %lld %lld", &x3, &y3, &z3, &x4, &y4, &z4);
/*        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        cin>>x3>>y3>>z3>>x4>>y4>>z4;*/
        answer(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
    }
}