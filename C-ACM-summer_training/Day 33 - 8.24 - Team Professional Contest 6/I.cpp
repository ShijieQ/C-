#include<map>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1000000+100;
int a[maxn];
map<int, int> mp;

struct node{
    int l, r;
    int id;
    int k;
    int ans;
}q[maxn];

bool cmp1(struct node a, struct node b){
    return a.k == b.k ? a.r < b.r : a.k < b.k;
}

bool cmp2(struct node a, struct node b){
    return a.id < b.id;
}

void insert(int n){
    mp.count(n) ? mp[n]++ : mp[n] = 1;
}

void clean(int n){
    mp[n] == 1 ? mp.erase(n) : mp[n]--;
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    init();
    int m, Q;
    while(cin>>m>>Q){
        if(m == 0 && Q == 0){
            cout<<endl;
            break;
        }
        for(int i = 1; i <= m; i++){
            cin>>a[i];
        }
        int len = int (sqrt(m));
        for(int i = 1; i <= Q; i++){
            cin>>q[i].l>>q[i].r;
            q[i].id = i;
            q[i].k = q[i].l / len;
        }
        sort(q+1, q+Q+1, cmp1);
        int L = 1, R = 1;
        insert(a[1]);
        for(int i = 1; i <= Q; i++){
            int flag = 0;
            while(R < q[i].r){
                insert(a[++R]);
            }
            while(L > q[i].l){
                insert(a[--L]);
            }
            while(L < q[i].l){
                clean(a[L++]);
            }
            while(R > q[i].r){
                clean(a[R--]);
            }
            for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it){
                if(it->second >= 2){
                    q[i].ans = it->first;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                q[i].ans = 0;
            }
        }
        sort(q+1, q+Q+1, cmp2);
        for(int i = 1; i <= Q; i++){
            if(q[i].ans == 0){
                cout<<"OK"<<endl;
            }
            else   
                cout<<q[i].ans<<endl;
        }
        cout<<endl;
        mp.clear();
    }
}
/*
10 5
3
2
3
4
9
7
3
8
4
1
1 3
2 6
4 10
3 7
2 6

5 2
1
2
3
1
2
2 4
1 5
*/