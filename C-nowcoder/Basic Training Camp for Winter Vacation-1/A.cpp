#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+10;
pair<long long int, long long int> p[maxn];

int main(){
    long long int n, X;
    cin>>n>>X;
    for(int i = 1; i <= n; i++){
        cin>>p[i].first>>p[i].second;
    }
    for(int i = n; i >= 1; i--){
        long long int temp = p[i].first;
        long long int shit = p[i].second;
        if(temp == 1){
            X -= shit;
        }
        else if(temp == 2){
            X += shit;
        }
        else if(temp == 3){
            X /= shit;
        }
        else {
            X *= shit; 
        }
    }
    cout<<X<<endl;
    return 0;
}