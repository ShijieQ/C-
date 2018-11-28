#include<iostream>
#include<algorithm>
#include<cstring>

#define X 105
#define Y 80
using namespace std;
const double k = 0.0000001;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
double x[maxn], y[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nx, ny;
    double w;
    while(cin>>nx>>ny>>w){
        int flag = 1;
        if(nx == 0 && ny == 0 && w == 0.0)
            break;
        x[0] = 0;
        y[0] = 0;
        for(int i = 1; i <= nx; i++){
            cin>>x[i];
        }
        for(int i = 1; i <= ny; i++){
            cin>>y[i];
        }
        sort(x+1, x+nx+1);
        for(int i = 1; i <= nx; i++){
            if(x[i] - x[i-1] - w > k){
                flag = 0;
                break;
            }
        }
        if(75 - x[nx] - w/2 > k){
            flag = 0;
        }
        sort(y+1, y+ny+1);
        for(int i = 1; i <= ny; i++){
            if(y[i] - y[i-1] - w > k){
                flag = 0;
                break;
            }
        }
        if(100 - y[ny] - w/2 > k){
            flag = 0;
        }
        if(flag)    
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
}
/*
8 11 10.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
8 10 10.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
0.0 10.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
4 5 20.0
70.0 10.0 30.0 50.0
30.0 10.0 90.0 50.0 70.0
4 5 20.0
60.0 10.0 30.0 50.0
30.0 10.0 90.0 50.0 70.0
*/