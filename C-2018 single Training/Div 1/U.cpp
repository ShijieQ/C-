#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 25;
int a[maxn];

int main(){
    int n, k, m;
    while(scanf("%d%d%d", &n, &k, &m) != EOF){
        if(!n && !k && !m){
            break;
        }
        for(int i = 0; i < n; i++){
            a[i] = i+1;
        }
        int num = n;
        int k1 = 0, k2 = n-1;
        while(num){
            int tem1 = 0;
            int i;
            int ans1, tmp1;
            for(i = k1; ; ){
                if(i == n){
                    i = 0;
                }
                if(a[i] != 0){
                    tem1++;
                    if(tem1 == k){
                        ans1 = a[i];
                        tmp1 = i;
                        k1 = i+1;
                        break;
                    }
                }
                i++;
                if(i == n){
                    i = 0;
                }
            }
            tem1 = 0;
            int ans2, tmp2;
            for(i = k2; ; ){
                if(i == -1){
                    i = n-1;
                }
                if(a[i] != 0){
                    tem1++;
                    if(tem1 == m){
                        ans2 = a[i];
                        tmp2 = i;
                        k2 = i-1;
                        break;
                    }
                }
                i--;
                if(i == -1){
                    i = n-1;
                }
            }
            printf("%3d", ans1);
            num--;
            if(ans1 == ans2){
                if(num){
                    cout<<",";
                }
            }
            else{
                num--;
                if(!num){
                    printf("%3d", ans2);
                }
                else{
                    printf("%3d,", ans2);
                }
            }
            a[tmp1] = a[tmp2] = 0;
        }
        cout<<endl;
    }
}