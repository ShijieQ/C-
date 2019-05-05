#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 1, 5};
    test.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}