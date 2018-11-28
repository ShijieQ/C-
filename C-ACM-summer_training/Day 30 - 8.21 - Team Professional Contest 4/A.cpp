#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const long long INF = 1e18;
const int maxn = 505;/*
int v[20][20];
long long int G[20];*/
long long int F[505][505];


struct Node{
    long long a, b;
    void print(){
        cout<<"("<<a<<","<<b<<") ";
    }
    bool operator < (const Node& rhs) const{
        return a < rhs.a || (a == rhs.a && b < rhs.b);
    }
}D[maxn];

long long jud(long long a, int b, long long que){
    long long ans = 1;
    for(int i = 0; i < b; i++){
        if(ans > (que+a+i-1) / (a+i)) 
            return que+1;
        ans *= (a+i); 
    }
    return ans;
}

int solve(long long que){
    long long temp = que;
    int num = 0;
    for(int i = 1; i <= 8; i++){
        que *= i;
        long long l = 1, r = INF, m;
        while(l <= r){
            m = (l+r) / 2;
            long long ans = jud(m, i, que);
//            cout<<ans<<"  "<<que<<endl;
            if(ans == que){
                if(i >= m) 
                    break;
                D[num].a = m+i-1;
                D[num].b = i;
                num++;
                if(m-1 != i){
                    D[num].a = m+i-1;
                    D[num].b = m-1;
                    num++;
                }
                break;
            }
            else if(ans > que) 
                r = m-1;
            else 
                l = m+1;
        }
    }

    que = temp;
    for(int i = 9; i < 53; i++){//手动二分算出来的i的最大值
        for(int j = 9; j <= i/2; j++){
            if(F[i][j] > que) 
                break;
            if(F[i][j] == que){
                D[num].a = i;
                D[num].b = j;
                num++;
                if(i-j != j){
                    D[num].a = i;
                    D[num].b = i-j;
                    num++;
                }
            }
        }
    }

    return num;
}

void init(){/*
    G[0] = 1;
    for(int i = 1; i < 20; i++){
        G[i] = i*G[i-1];
    }*/
    F[0][0] = 1;
    for(int i = 1; i <= 500; i++){
        F[0][i] = 0;
        F[i][0] = 1;
        F[i][i] = 1;
    }
    for(int i = 2; i <= 500; i++){
        for(int j = 1; j < i; j++){
            F[i][j] = F[i-1][j] + F[i-1][j-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin>>T;
    while(T--){
        long long int m;
        int ans;
        cin>>m;
        ans = solve(m);
        /*
        for(int i = 7; i < maxn; i++){
            for(int j = 7; j <= i/2; j++){
                if(F[i][j] > m) 
                    break;
                if(F[i][j] == m){
                    D[ans].a = i;
                    D[ans].b = j;
                    ans++;
                    if(i-j != j){
                        D[ans].a = i;
                        D[ans].b = i-j;
                        ans++;
                    }
                }
            }
        }
        */
        sort(D, D+ans);
        cout<<ans<<endl;
        for(int i = 0; i < ans; i++){
            D[i].print();
        }
        cout<<endl;
    }
}
