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

string a, b;
vector<vector<int>> dp;
vector<vector<int>> vis;

void getLCS(int i, int j) {
    if (i == 0 || j == 0) {
        return ;
    }
    if (vis[i][j] == 1) {
        getLCS(i - 1, j - 1);
        cout<<a[i];
    }
    else if (vis[i][j] == 2) {
        getLCS(i - 1, j);
    }
    else {
        getLCS(i, j - 1);
    }
}

int main() {
    cin>>a>>b;
    int m = a.length(), n = b.length();
    a = " " + a; b = " " + b;
    dp.resize(m + 1, vector<int> (n + 1));
    vis.resize(m + 1, vector<int> (n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                vis[i][j] = 1;
            }
            else {
                if (dp[i - 1][j] >= dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j];
                    vis[i][j] = 2;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    vis[i][j] = 3;
                }
            }
        }
    }
    cout<<"The length of LCS is "<<dp[m][n]<<"."<<endl;
    cout<<"The LCS is : ";
    getLCS(m, n);
    cout<<endl;
    return 0;
}