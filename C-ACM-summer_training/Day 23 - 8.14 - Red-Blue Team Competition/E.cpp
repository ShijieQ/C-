/* 
    unsolved
    */
#include<iostream>
#include<algorithm>
#define maxn 100000+5
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int lx, ly;
    int rx, ry;
    double k;
    bool operator <(const node b) const{
        return k < b.k;
    //    return lx == b.lx ? ly == b.ly?k < b.k:ly < b.ly : lx < b.lx;
    }
}a[maxn];

long long int num(int tem_k, int i, int j){
    for(int j = i+1; a[j].k == tem_k; j++){

    }
}

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++){
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1 > x2){
                a[i].lx = x2;
                a[i].ly = y2;
                a[i].rx = x1;
                a[i].ry = y1;
            }
            else{
                a[i].lx = x1;
                a[i].ly = y1;
                a[i].rx = x2;
                a[i].ry = y2;
            }
            if(x1 == x2){
                a[i].k = INF;
            }
            else{
                a[i].k = double (a[i].ry - a[i].ly)/(a[i].rx - a[i].lx);
            }
        }
        sort(a+1, a+n+1);
        /*
        for(int i = 1; i <= n; i++){
            cout<<a[i].lx<<" "<<a[i].ly<<" "<<a[i].rx<<" "<<a[i].ry<<" "<<a[i].k<<endl;
        }
        */
        for(int i = 0; i <= n; i++){
            double tem_k = a[i].k;
            
        }
    }
    return 0;
}