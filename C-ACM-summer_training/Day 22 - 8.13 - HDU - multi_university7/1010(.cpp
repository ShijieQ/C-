#include <stdio.h>
#include <string.h>
#define N 3
#define mod 1000007
#define ll long long
struct Matrix{
    ll mat[N][N];//乘积时(可能接近mod^2)超出int,
};
struct Matrix mul(struct Matrix a,struct Matrix b)
{
    int i,j,k;
    struct Matrix res;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            res.mat[i][j] = 0;
            for(k=0;k<N;k++)
            {
                res.mat[i][j] += a.mat[i][k]*b.mat[k][j];
                res.mat[i][j] %= mod;//必须每次取余
            }
        }
    }
    return res;
}
struct Matrix mul_matrix(struct Matrix b, int c)
{
    struct Matrix res = {
        c/n,0,0,
        0,c/n,0,
        0,0,c/n
    };//单位阵
    while(n)
    {
        if(n&1)
            res = mul(res,b);
        n >>= 1;
        b = mul(b,b);
    }
    return res;
}
int main()
{
    int T,f[2],a,b,c,n;
    struct Matrix tmp,res;
    struct Matrix tmp_matrix = {//中间矩阵
        0,0,0,//每组测试将此三处的值更新为b,a,c
        1,0,0,
        0,0,1
    };
    memset(tmp.mat,0,sizeof(tmp.mat));//tmp值只有(0,0),(1,0)需要填入f(2),f(1)的值,其余不变
    tmp.mat[2][0] = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&f[0],&f[1],&a,&b,&c,&n);
        if(n == 1 || n == 2)
            printf("%d\n",(f[n-1]+mod)%mod);//注意对负值的处理
        else{
            tmp_matrix.mat[0][0] = b;
            tmp_matrix.mat[0][1] = a;
            tmp_matrix.mat[0][2] = c/n;
            tmp.mat[0][0] = f[1];
            tmp.mat[1][0] = f[0];
            //实际上最终我们只需进行矩阵和向量(f(2),f(1),1)'的运算,但是因为在进行矩阵快速幂时我们已经定义了矩阵乘积
            //所以不妨借用,最后取(0,0)的值即可
            res = mul(mul_matrix(tmp_matrix,n-2,c),tmp);
            printf("%lld\n",(res.mat[0][0]+mod)%mod);
        }
    }
    return 0;
}        
