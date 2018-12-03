#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 20+5;
double a[maxn][2];
double ans[maxn];
int n, r;
double ave = 0.0;

void cal(int k, double ans_, string s, int num){
    //cout<<"k = "<< k << "  "<< "ans_ = "<< ans_ << " " << "num = "<<num<<endl;
    if(num == 1 && k == n){
        int len = s.length();
        //cout<<ans_<<endl;
        ave += ans_;
        for(int i = 0; i < len; i++){
            int temp = s[i]+1;
        //    cout<<temp<<" ";
            ans[temp] += ans_;
        }
        //cout<<endl;
        return ;
    }
    if(num == 0){
        return ;
    }
    if(k == n){
        return ;
    }
    cal(k+1, ans_*a[k+1][1], s + char(k), num-1);
    cal(k+1, ans_*a[k+1][0], s, num);
}

int main(){
    /*
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    */
    int cnt = 1;
    while(scanf("%d%d", &n, &r) != EOF && (n || r)){
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++){
            scanf("%lf", &a[i][1]);
            a[i][0] = 1 - a[i][1];
        }
        if(r == 0){
            for(int i = 1; i <= n; i++){
                ans[i] = 0;
            }
        }
        else if(r == 1){
            for(int i = 1; i <= n; i++){
                double temp = a[i][1];
                for(int j = 1; j <= n; j++){
                    if(i != j){
                        temp *= a[j][0];
                    }
                }
                ans[i] = temp;
                ave += temp;
            }
            for(int i = 1; i <= n; i++){
                ans[i] /= ave;
            }
        }
        else{
            cal(0, 1, "", r+1);
            //cout<<"ave = "<<ave<<endl;
            for(int i = 1; i <= n; i++){
                ans[i] /= ave;
            }
        }
        printf("Case %d:\n", cnt++);
        for(int i = 1; i <= n; i++){
            printf("%.6f\n", ans[i]);
        }
        ave = 0.0;
    }
}
/*
3 2
0.10
0.20
0.30
5 1
0.10
0.10
0.10
0.10
0.10
*/

/*
0.014
0.024
0.054

sum = 0.014+0.024+0.054 = 0.092

0.038  --> 0.038/0.092  
0.078  --> 0.078/0.092
0.068  --> 0.068/0.092
*/
