#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+5;
int a[maxn];

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sum /= n;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < sum){
            a[i+1] -= sum-a[i];
            a[i] = sum;
            cnt++;
        }
        if(a[i] > sum){
            a[i+1] += a[i]-sum;
            a[i] = sum;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}