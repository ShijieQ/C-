#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3005;
int m[maxn], n[maxn], ans[maxn];

int main(){
    /*
    freopen("N.in", "r", stdin);
    freopen("N.out", "w", stdout);
    */
    int a, b, cas = 0;
    while(cin>>a>>b){
        /*if(cas){
            cout<<endl;
        }
        cas++;
        */
        memset(m, 0, sizeof(m));
        memset(n, 0, sizeof(n));
        memset(ans, 0, sizeof(ans));
        int k = 0;
        ans[k++] = a/b;
        int tem = a;    
        a = a % b;
        while(!m[a] && a){
            m[a] = k;
            n[k] = a;
            ans[k++] = 10*a/b;
            a = 10*a%b;
        }
        printf("%d/%d = %d.", tem, b, ans[0]);
        for(int i = 1; i < k && i <= 50; i++){
            if(n[i] == a){
                cout<<"(";
            }
            cout<<ans[i];
        }
        if(k > 50){
            cout<<"...";
        }
        int cnt = 0;
        if(a == 0){
            cout<<"(0";
            cnt = 1;
        }
        else{
            cnt = k - m[a];
        }
        cout<<")"<<endl;
        printf("   %d = number of digits in repeating cycle\n\n", cnt);
    }
}