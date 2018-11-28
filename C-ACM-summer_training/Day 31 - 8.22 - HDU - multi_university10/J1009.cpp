#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;

struct node{
    int k;
    long long int ans;
    int id;
    bool operator < (const node& other) const{
        return k < other.k;
    }
}a[maxn];

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

bool cmp(struct node a, struct node b){
    return a.id < b.id;
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        cin>>a[i].k;
        a[i].id = i;
    }
    sort(a+1, a+T+1);
    a[0].k = 0;
    a[0].ans = 0;
    for(int k = 1; k <= T; k++){
        long long int ans = 0;
        for(int i = a[k-1].k+1; i <= a[k].k; i++){
            for(int j = 1; j <= i-1; j++){
                if(gcd(i+j, i-j) == 1)
                    ans++;
            }
        }
        a[k].ans = a[k-1].ans + ans;
    }
    sort(a+1, a+T+1, cmp);
    for(int i = 1; i <= T; i++){
        cout<<a[i].ans<<endl;
    }
}