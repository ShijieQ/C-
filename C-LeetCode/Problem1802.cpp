class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int ans = 1, l = index, r = index;
        int res = maxSum - n;
        while (res > 0) {
            int len = r-l+1;
            if (res < len || len == n) {
                break;
            }
            res -= len;
            ans++;
            l = max(0, l-1);
            r = min(n-1, r+1);
        }
        return ans+res/n;
    }
};