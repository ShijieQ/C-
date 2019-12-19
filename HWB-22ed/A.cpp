#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6+10;
int ans[maxn];

void init() {
    ans[1] = ans[0] = 0;
    for (int i = 1; i < maxn; i++) {
        for (int j = i+i; j < maxn; j += i) {
            if ((j^(j-i)) == i) {
                ans[j]++;
            }
        }
        ans[i] += ans[i-1];
    }
}

int main() {
    init();
    int T;
    cin>>T;
    while (T--) {
        int temp;
        cin>>temp;
        cout<<ans[temp]<<endl;
    }
    return 0;
}