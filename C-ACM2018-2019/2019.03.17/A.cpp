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
stack<int> s;
char q[10];

int main(){
    int n;
    scanf("%d", &n);
    int now = 1;
    int ans = 0;
    for(int i = 1; i <= 2*n; i++){
        int temp;
        scanf("%s", q);
        if(q[0] == 'a'){
            scanf("%d", &temp);
            s.push(temp);
        }
        else{
            if(s.empty()){
                now++;
            }
            else{
                if(s.top() != now){
                    //cout<<"now = "<<now<<endl;
                    while(!s.empty()){
                        s.pop();
                    }
                    now++;
                    ans++;
                }
                else{
                    s.pop();
                    now++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}