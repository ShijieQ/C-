#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> vis;
        sort(nums.begin(), nums.end());
        int siz = nums.size();
        for (int i = 0; i < siz - 3; i++) {
            for (int j = i + 1; j < siz - 2; j++) {
                int l = j + 1, r = siz - 1; 
                while (l < r) {
                    int temp = nums[i] + nums[j] + nums[l] + nums[r];
                    if (temp > target) {
                        r--;
                    }
                    else if (temp < target) {
                        l++;
                    }
                    else {
                        vis.insert({nums[i], nums[j], nums[l], nums[r]});
                        r--, l++;
                    }
                }
            }
        }
        vector<vector<int>> ans(vis.begin(), vis.end());
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> check = {0, 0, 0, 0};
    vector<vector<int>> ans = test.fourSum(check, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}