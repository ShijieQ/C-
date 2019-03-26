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
int a[maxn];
int num = 0;
deque<int> q;

int main(){
    int n;
    long long int k;
    cin>>n>>k;
    int maxx = -INF;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] > maxx){
            maxx = a[i];
            num = i;
        }
        q.push_back(a[i]);
    }
    int win = q.front();
    q.pop_front();
    int cnt = 0;
    if(k <= n){
        while(!q.empty() && cnt < k){
            if(q.front() < win){
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
            else{
                q.push_back(win);
                win = q.front();
                q.pop_front();
                cnt = 1;
            }
        }
        cout<<win<<endl;
    }
    else{
        cout<<maxx<<endl;
    }
    return 0;
}