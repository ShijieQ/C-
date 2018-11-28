#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 300000+5
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[maxn];
        long long int sum = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            sum += a[i]; 
        }
        long long avg = sum/n;
    }
}