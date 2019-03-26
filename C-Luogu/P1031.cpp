#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+10;
int a[maxn];

int main(){
    int n, ave = 0, cnt = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ave += a[i];
    }
    ave /= n;
    for(int i = 1; i <= n - 1; i++){
        if(a[i] != ave){
            a[i+1] += (a[i] - ave);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

