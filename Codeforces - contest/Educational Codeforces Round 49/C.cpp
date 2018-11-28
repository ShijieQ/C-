#include<bits/stdc++.h>
using namespace std;
int T;
int n,l[10005],t;
int s[10005];
int spa;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        spa=0;
        int it=0;
        memset(l,0,sizeof(l));
        memset(s,0,sizeof(s));
        for(int i=0; i<n; i++){
            scanf("%d",&t);
            l[t]++;
            if(l[t]==2)
                s[it++]=t;
            else if(l[t]==4)
                spa= spa==0?t:min(spa,t);
        }
        int cl,cr,cd;
        if(spa!=0)
            printf("%d %d %d %d\n",spa,spa,spa,spa);
        else{
            sort(s,s+it);
            //cd=s[1]-s[0];
            cl=s[0];
            cr=s[1];
            for(int i=2; i<it; i++){
                if((float)s[i]/(float)s[i-1]<(float)cr/(float)cl){
                    //cd=s[i]-s[i-1];
                    cl=s[i-1];
                    cr=s[i];
                }
            }
            printf("%d %d %d %d\n",cl,cl,cr,cr);
        }
    }
    return 0;
}