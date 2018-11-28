#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
double yizi[] = {0, 0, 8.99, 2.48, 1.59, 1.24, 1.05, 0.93, 0.84, 0.77, 0.72};

int main(){
    freopen("fangcha.in", "r", stdin);
    freopen("fangcha.out", "w", stdout);
    int n;
    cin>>n;
    double a[maxn];
    double average = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        average += a[i];
    }
    average /= n;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += ((average - a[i])*(average - a[i]));
    }
    cout<<average<<endl;
    cout<<sqrt(ans/(n-1))<<endl;
    cout<<sqrt(ans/(n-1))*yizi[n]<<endl;
}