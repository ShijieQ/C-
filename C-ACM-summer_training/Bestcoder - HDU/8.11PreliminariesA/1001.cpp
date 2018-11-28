#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxn 1005
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int a[maxn];
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int flag = 0;
        sort(a+1, a+n+1, cmp);
        for(int i = 1; i <= n-2; i++){
            for(int j = i+1; j <= n-1; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i] < a[j]+a[k] && a[j] < a[i]+a[k] && a[k] < a[i]+a[j]){
                        flag = 1;
                        cout<<a[i]+a[j]+a[k]<<endl;
                        break;
                    }
                }
                if(flag)
                	break;
            }
            if(flag)
            	break;
        }
        if(!flag){
            cout<<"-1"<<endl;
        }
    }
}
