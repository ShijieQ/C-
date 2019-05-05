#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<vector<bool> > dp(lens + 1, vector<bool> (lenp + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= lenp; i++) {
            if (p[i - 1] == '*' && i - 2 >= 0) {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*' && j - 2 >= 0) {
                    if (p[j - 2] != s[i - 1]) {
                        dp[i][j] = dp[i][j - 2];
                    }
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i][j - 2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};

int main() {
    Solution test;
    bool flag = test.isMatch("aab", "c*a*b");
    cout<<flag<<endl;
    return 0;
}