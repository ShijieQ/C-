#include<bits/stdc++.h>

using namespace std;
const int maxn = 10+10;
vector<int> x;
int num = 0;

bool Place(int k, int i) {
    for (int j = 0; j < k; j++) {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return false;
        }
    }
    return true;
}

void OutputAns(int num, int n) {
    cout<<"Case #"<<num<<": "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void NQueens(int k, int n) {
    for (int i = 0; i < n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n - 1) {
                OutputAns(++num, n);
            }
            else {
                NQueens (k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    while (cin>>n) {
        x.resize(n);
        NQueens(0, n);
        cout<<"                  num = "<<num<<endl;
        num = 0;
    }
}