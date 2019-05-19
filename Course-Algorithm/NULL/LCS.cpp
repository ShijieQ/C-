#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > ans;
string x, y;

int lcs(int i, int j) {
    if (ans[i][j] > 0) {
        return ans[i][j];
    }
    if (i == 0 || j == 0) {
        return 0;
    }
    if (x[i] == y[j]) {
        ans[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else {
        ans[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
    return ans[i][j];
}

int main() {
    cin>>x>>y;
    x = " " + x;
    y = " " + y;
    ans.resize(x.length(), vector<int> (y.length()));
    cout<<lcs(x.length() - 1, y.length() - 1)<<endl;
    return 0;
}