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
int a[maxn];

int main(){
    int n;
    cin>>n;
    bool flag = 0;
    for(int i = n; i >= 0; i--){
        cin>>a[i];
    }
    for(int i = n; i >= 0; i--){
        if((i != n && a[i] > 0)){
            cout<<"+";
            flag = 1;
        }
        if((abs(a[i]) > 1) || (!i && a[i])){
            cout<<a[i];
        }
        if(a[i] == -1 && i){
            cout<<"-";
            flag = 1;
        }
        if(i > 1 && a[i]){
            cout<<"x^"<<i;
            flag = 1;
        }
        if(i == 1 && a[i]){
            cout<<"x";
            flag = 1;
        }
    }
    cout<<endl;
    return 0;
}
// #include<map>
// #include<set>
// #include<cmath>
// #include<queue>
// #include<stack>
// #include<cstdio>
// #include<vector>
// #include<cstring>
// #include<iostream>
// #include<algorithm>

// using namespace std;
// const int maxn = 2e5+10;

// int main(){
//     int n;
//     cin>>n;
//     for(int i = n; i >= 0; i--){
//         int a;
//         cin>>a;
//         if(i != n && a > 0){
//             cout<<"+";
//         }
//         if(abs(a) > 1 || (!i && a)){
//             cout<<a;
//         }
//         if(a == -1 && i){
//             cout<<"-";
//         }
//         if(i > 1 && a){
//             cout<<"x^"<<i;
//         }
//         if(i == 1 && a){
//             cout<<"x";
//         }
//     }
//     cout<<endl;
//     return 0;
// }
