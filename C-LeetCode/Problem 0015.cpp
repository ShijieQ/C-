#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0 || (l > i + 1 && nums[l] == nums[l - 1])) {
                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] > 0 || (r < len - 1 && nums[r] == nums[r + 1])) {
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }
        return ans;
    }
};