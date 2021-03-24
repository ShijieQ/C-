class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int now) {
        if (now == nums.size()) {
            ans.push_back(nums);
            return ;
        }
        int length = nums.size();
        for (int i = now; i < length; i++) {
            swap(nums[now], nums[i]);
            dfs(ans, nums, now+1);
            swap(nums[now], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, nums, 0);
        return ans;
    }
};