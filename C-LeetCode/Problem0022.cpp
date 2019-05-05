#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> ans;
public:

    void dfs(int ln, int rn, string a) {
        if (!ln && !rn) {
            ans.push_back(a);
            return ;
        }
        if (ln) {
            dfs(ln - 1, rn, a + "(");
        }
        if (ln < rn) {
            dfs(ln, rn - 1, a + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return ans;
    }
};

class Solution_DP {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1, vector<string> ());
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto &u : dp[j]) {
                    for (auto &v : dp[i - 1 - j]) {
                        dp[i].push_back("(" + u + ")" + v);
                    }
                }
            }
        }
        return dp[n];
    }
};