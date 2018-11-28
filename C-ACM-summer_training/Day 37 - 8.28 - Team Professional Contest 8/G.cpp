#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10000+10;
int a[maxn];
int m[maxn];

using namespace std;
int main(){
    int n, h, b, e;
    while(scanf("%d %d %d %d", &n, &h, &b, &e) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n-h+1; i++){
            m[i] = *min_element(a+i, a+i+h);
        }
        for(int i = n-h+2; i <= n; i++){
            m[i] = m[i-1];
        }
        int tem = e-b;
        b-h+1 < 1? b = 1:b = b-h+1;
        e = b+tem;
        int num = 0;
        for(int i = b; i <= e; i++){
            if(!num)
                num++;
            else{
                ...
            }
            if(m[i] < a[i]){
                num+=h;
            }
        }
    }
}