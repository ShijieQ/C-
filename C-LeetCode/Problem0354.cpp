class Solution {
public:
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1]:a[0] < b[0];
        }
    };

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp());
        int size = envelopes.size();
        vector<int> dp(size, 1);
        int ans = 1;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};