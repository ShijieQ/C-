#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

#define maxn 1000000+5
using namespace std;
int num[maxn], d[maxn];
int x = 1, y, n, m;

int main(){
    ios::sync_with_stdio(false);
    int t, maxx = 0;
    cin>>t;
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= t; i++){
        int tem;
        cin>>tem;
        num[tem]++;
        maxx = max(maxx, tem);
    }
    for(int i = 1; i < maxx; i++){
        if(num[i]%4 != 0){
            x = i;
            break;
        }
    }
    int flag2 = 1;
    for(n = 1; n <= t; n++){
        if(t % n == 0){  
            m = t/n;
            y = n+m-maxx-x;
            memset(d, 0, sizeof(d));
            for(int i = 1; i <= n; i++){  
                for(int j = 1; j <= m; j++){
                    int temp = abs(i-x)+abs(j-y);
                    d[temp]++;   
                }
            }
            int flag = 1;
            for(int i = 0; i <= maxx; i++){
                if(num[i] != d[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout<<n<<" "<<m<<endl;
                cout<<x<<" "<<y<<endl;
                flag2 = 0;
                break;
            }
        }
    }
    if(flag2)
        cout<<"-1"<<endl;
    return 0;
}