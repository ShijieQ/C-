#include<queue>
#include<iostream>
#include<algorithm>
#define maxn 100000+5

using namespace std;

struct node1{
    int p;
    double z;
    int cost;
    int id;
    bool operator < (const node &other) const{
        if(p < other.p)
            return true;
        }else{
            return false;
        }
    }
}a[maxn];

struct node2{
    int p;
    double z;
    int cost;
    int id;
    bool operator < (const node &other) const{
        if(z < other.z)
            return true;
        }else if(z == other.z){
            return cost > other.cost;
        }else{
            return false;
        }
    }
}b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        priority_queue <struct node> d;

        for(int i = 1, j = 0; i <= n; i++){
            char ch;
            cin>>ch;
            int p, cost;
            double z;
            if(ch == 'C'){
                if(d.empty()){
                    cout<<endl;
                }else{
                    struct node tem = d.top(); 
                    cout<<tem.id<<" ";
                }
            }else{
                cin>>p>>z>>cost;
                a[++j].p = p;
                a[j].z = z;
                a[j].cost = cost;
                a[j].id = j;
                d.push(a[j]);
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
P 9600000 7 72
7
P 1200000 1 40
P 7200000 5 100
C
P 9600000 3 200
C
P 7200000 12 220
C
*/