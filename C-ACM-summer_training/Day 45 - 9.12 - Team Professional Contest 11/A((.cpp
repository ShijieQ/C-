#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define gcd(a,b) __gcd(a,b)
#define mset(a,x) memset(a,x,sizeof(a))
#define FIN     freopen("input","r",stdin)
#define FOUT    freopen("output","w",stdout)
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const int mod=1e9+7;
typedef long long ll;
using namespace std;
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll qpow(ll a,ll b){ll r=1,t=a; while(b){if(b&1)r=(r*t)%mod;b>>=1;t=(t*t)%mod;}return r;}
inline ll inv1(ll b){return qpow(b,mod-2);}
inline ll inv2(ll b){return b==1?1:(mod-mod/b)*inv2(mod%b)%mod;}
inline ll exgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1;y=0;return a;}ll r=exgcd(b,a%b,y,x);y-=(a/b)*x;return r;}
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int r,n;
char Map[105][105];
int cal(){
    int suml=0,sumr=0;
    for (int j=1;j<=r+3;j++){
        for (int k=0;k<5;k++){
            if(Map[j][k]=='-') suml++;
        }
    }
    for (int j=1;j<=r+3;j++){
        for (int k=6;k<11;k++){
            if(Map[j][k]=='-') sumr++;
        }
    }
    if (suml>=sumr) return 0;
    return 1;
}
void work(int Index,int i){
    int temp=cal();
    if(Map[Index][4]=='-'&&Map[Index][6]=='-'){
        if(temp==0) Map[Index][4]=i+'a';
        else Map[Index][6]=i+'a';
    }
    else if(Map[Index][4]=='-'||Map[Index][6]=='-'){
        if(Map[Index][4]=='-') Map[Index][4]=i+'a';
        else Map[Index][6]=i+'a';
    }
 
    else if(Map[Index][2]=='-'&&Map[Index][8]=='-'){
        if(temp==0) Map[Index][2]=i+'a';
        else Map[Index][8]=i+'a';
    }
    else if(Map[Index][2]=='-'||Map[Index][8]=='-'){
        if(Map[Index][2]=='-') Map[Index][2]=i+'a';
        else Map[Index][8]=i+'a';
    }
 
    else if(Map[Index][0]=='-'&&Map[Index][10]=='-'){
        if(temp==0) Map[Index][0]=i+'a';
        else Map[Index][10]=i+'a';
    }
    else if(Map[Index][0]=='-'||Map[Index][10]=='-'){
        if(Map[Index][0]=='-') Map[Index][0]=i+'a';
        else Map[Index][10]=i+'a';
    }
    else if(Map[Index][5]=='-') {Map[Index][5]=i+'a';}
 
    else if(Map[Index][1]=='-'&&Map[Index][9]=='-'){
        if(temp==0) Map[Index][1]=i+'a';
        else Map[Index][9]=i+'a';
    }
    else if(Map[Index][1]=='-'||Map[Index][9]=='-'){
        if(Map[Index][1]=='-') Map[Index][1]=i+'a';
        else Map[Index][9]=i+'a';
    }
}
int main (){
    scanf ("%d%d",&r,&n);
 
    for (int i=1;i<=r+3;i++) scanf ("%s",Map[i]);
 
    for (int i=0;i<n;i++){
        int sum1=0,sum2=0;
 
        for (int j=0;j<11;j++){
            if(Map[2][j]=='-') sum1++;
            if(Map[r/2+3][j]=='-') sum2++;
        }
 
        if(!sum1&&!sum2){
            int Index;
            int maxn=0;
            for (int j=1;j<=r+3;j++){
                int sum=0;
                for (int k=0;k<11;k++){
                    if(Map[j][k]=='-') sum++;
                }
                maxn=max(maxn,sum);
            }
            int minn=INF;
             for (int j=1;j<=r+3;j++){
                int sum=0;
                for (int k=0;k<11;k++){
                    if(Map[j][k]=='-') sum++;
                }
                if(sum==maxn){
                    int mindis=min(abs(j-(r+3)),min(abs(j-1),abs(j-(r/2+2))));
                    if(minn>mindis){
                        Index=j;
                        minn=mindis;
                    }
                }
            }
            work(Index,i);
        }
        else{
            int Index;
            if(sum1>=sum2) Index=2;
            else if(sum1<sum2) Index=r/2+3;
 
            work(Index,i);
        }
    }
    for (int i=1;i<=r+3;i++) printf ("%s\n",Map[i]);
    return 0;
}
