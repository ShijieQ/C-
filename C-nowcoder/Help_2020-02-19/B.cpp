#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[16];
    for (int i = 0; i < n; i++) {
        char ch;
        int num;
        cin>>ch>>num;
        if (ch != 'J') {
            a[num]++;
        }
        else {
            a[0]++;
        }
    }
    int ans = 0;
    if (a[0] == 2) {
        ans += 5;
    }
    n -= a[0];
    a[0] = 0;
    for (int i = )
    return 0;
}