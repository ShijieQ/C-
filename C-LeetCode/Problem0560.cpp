#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;
        for (int i = 0; i < len - 1; i++) {
            nums[i + 1] += nums[i];
            if (seen.find(nums[i] - k) != seen.end()) {
                ans += seen[nums[i] - k];
            }
            seen[nums[i]]++;
        }
        ans += seen[nums[len - 1] - k];
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 1, 1};
    int ans = test.subarraySum(nums, 2);
    cout<<ans<<endl;
    return 0;
}