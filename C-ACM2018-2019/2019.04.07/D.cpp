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
const int maxn = 2e5+10;

int main(){
    int n;
    cin>>n;
    if(n == 1 || n == 2){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
        cout<<"1 ";
        for(int i = 1; i <= n - 1; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"2 "<<n<<endl;
    }
    return 0;
}