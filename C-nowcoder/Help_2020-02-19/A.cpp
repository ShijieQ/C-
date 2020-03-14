#include<bits/stdc++.h>

using namespace std;
int a[11];
int cnt = 0;

int dfs(int i) {
    while (a[i] < 2) {
        a[i] += dfs(i-1);
    }
    if (a[i] >= 2) {
        a[i] -= 2;
        cnt += 1;
        return 1;
    }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cnt = 0;
        for (int i = 0; i < 10; i++) {
            cin>>a[i];
        }
        dfs(9);
        cout<<cnt<<endl;
    }
    return 0;
}