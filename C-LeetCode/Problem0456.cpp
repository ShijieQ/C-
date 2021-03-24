class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) {
            return false;
        }
        int m = -0x3f3f3f3f;
        stack<int> s;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < m) {
                return true;
            }
            while (!s.empty() && s.top() < nums[i]) {
                m = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};