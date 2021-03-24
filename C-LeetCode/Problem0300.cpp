class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), ans = 1;
        vector<int> dp(len+1, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

class Solution_NlogN {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), ans = 1;
        vector<int> d(len+1, 0);
        d[1] = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] > d[ans]) {
                ans++;
                d[ans] = nums[i];
            }
            else {
                int l = 1, r = ans, pos = 0;
                while (l <= r) {
                    int mid = (l+r)>>1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                d[pos+1] = nums[i];
            }
        }
        return ans;
    }
};