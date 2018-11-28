#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int n = 20000+5;

int m[n],phi[n],p[n],nump;
// euler
int make(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    phi[1]=1;
    for (int i=2;i<=n;i++){
        if (!m[i]){
            p[++nump]=i;
            phi[i]=i-1;    
        }    
        for (int j=1;j<=nump&&p[j]*i<n;j++){
            m[p[j]*i]=1;
            if (i%p[j]==0){
                phi[p[j]*i]=phi[i]*p[j];
                break;
            }
            else phi[p[j]*i]=phi[i]*(p[j]-1);
        }
    }
}

int main(){
    make();
    int n;
    while(cin>>n){
        cout<<phi[n]<<endl;
    }
    return 0;
}