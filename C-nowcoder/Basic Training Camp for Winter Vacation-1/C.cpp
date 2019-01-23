#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e3+50;
int val[maxn], get[maxn];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>val[i];
    }
    int v0 = get[1] = val[1];
    int aim = val[n];
    if(v0 <= val[n]){
        cout<<-1<<endl;
        return 0;
    }
    int num = 1;
    for(int i = 2; i < n; i++){
        if(val[i] < v0 && val[i] > aim){
            get[++num] = val[i];
        }
    }
    get[++num] = val[n];
    sort(get+1, get+1+num, cmp);
    for(int i = 2; i <= num; i++){
        
    }
}