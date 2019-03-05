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
const int maxn = 10;
int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int A, B, C;

void solve(){
    bool flag = 0;
    do{
        int a = num[0]*100 + num[1]*10 + num[2];
        int b = num[3]*100 + num[4]*10 + num[5];
        int c = num[6]*100 + num[7]*10 + num[8];
        if(B*a == A*b && B*c == C*b){
            cout<<a<<" "<<b<<" "<<c<<endl;
            flag = 1;
        }
    }while(next_permutation(num, num+9));
    if(!flag){
        cout<<"No!!!"<<endl;
    }
}

int main(){
    cin>>A>>B>>C;
    solve();
    return 0;
}