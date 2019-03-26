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
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
string s = "Dang";

int main(){
    int h, m;
    scanf("%d:%d", &h, &m);
    if(h <= 12){
        printf("Only %02d:%02d.  Too early to Dang.\n", h, m);
        return 0;
    }
    int ans = (h >= 12 ? h-12:h) + (m ? 1:0);
    for(int i = 1; i <= ans; i++){
        cout<<s;
    }
    cout<<endl;
    return 0;
}