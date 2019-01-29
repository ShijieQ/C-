#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e4+50;

int main(){
    int n;
    cin>>n;
    long long int ans = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;
        if(temp < 60){
            ans++;
        }
    }
    cout<<ans*400<<endl;
    return 0;
}