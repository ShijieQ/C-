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
const int maxn = 1111;
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
set<pair<int, int> > s;

int getnum(int k){
    int ans = 0;
    if(!k){
        return 6;
    }
    else{
        while(k){
            ans += num[k%10];
            k /= 10;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    n -= 4;
    if(n <= 0){
        cout<<0<<endl;
        return 0;
    }
    for(int i = 0; i <= 1111; i++){
        for(int j = 0; j <= 1111; j++){
            if(getnum(i)+getnum(j)+getnum(i+j) == n){
                s.insert(make_pair(i, j));
            }
        }
    }
    cout<<s.size()<<endl;
    return 0;
}