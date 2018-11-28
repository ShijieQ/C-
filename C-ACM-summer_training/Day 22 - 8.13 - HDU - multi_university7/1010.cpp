#include<stdio.h>
long long m,n,a,b,c,k;
long long mol=1000000007;
long long x1,x2,x3;
long long y1,y2,y3;
long long z1,z2,z3;
void f()
{
    long long h=k;
    if(h==1)
    {
        printf("%lld\n",m);
        return;
    }
    if(h==2)
    {
        printf("%lld\n",n);
        return;
    }
    long long r1=1,r2=0,r3=0;
    long long s1=0,s2=1,s3=0;
    long long t1=0,t2=0,t3=1;
    h-=2;
    while(h>=1)
    {
        int o1,o2,o3,p1,p2,p3,q1,q2,q3;
        if(h%2==1)
        {
            o1=(r1*x1+s1*x2+t1*x3)%mol;
            p1=(r1*y1+s1*y2+t1*y3)%mol;
            q1=(r1*z1+s1*z2+t1*z3)%mol;
            o2=(r2*x1+s2*x2+t2*x3)%mol;
            p2=(r2*y1+s2*y2+t2*y3)%mol;
            q2=(r2*z1+s2*z2+t2*z3)%mol;
            o3=(r3*x1+s3*x2+t3*x3)%mol;
            p3=(r3*y1+s3*y2+t3*y3)%mol;
            q3=(r3*z1+s3*z2+t3*z3)%mol;
 
            r1=o1,r2=o2,r3=o3;
            s1=p1,s2=p2,s3=p3;
            t1=q1,t2=q2,t3=q3;
        }
        o1=(x1*x1+y1*x2+z1*x3)%mol;
        p1=(x1*y1+y1*y2+z1*y3)%mol;
        q1=(x1*z1+y1*z2+z1*z3)%mol;
        o2=(x2*x1+y2*x2+z2*x3)%mol;
        p2=(x2*y1+y2*y2+z2*y3)%mol;
        q2=(x2*z1+y2*z2+z2*z3)%mol;
        o3=(x3*x1+y3*x2+z3*x3)%mol;
        p3=(x3*y1+y3*y2+z3*y3)%mol;
        q3=(x3*z1+y3*z2+z3*z3)%mol;
 
        x1=o1,x2=o2,x3=o3;
        y1=p1,y2=p2,y3=p3;
        z1=q1,z2=q2,z3=q3;
        h/=2;
    }
    n=(m*r2+n*s2+t2)%mol;
    n=(n+mol)%mol;
    printf("%lld\n",n);
}
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&m,&n,&a,&b,&c,&k);
        x1=0,y1=1,z1=0;
        x2=a,y2=b,z2=c/k;
        x3=0,y3=0,z3=1;
        f();
    }
}
