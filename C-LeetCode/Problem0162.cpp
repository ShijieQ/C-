class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        if (size == 2) {
            return nums[0] > nums[1] ? 0:1;
        }
        int l = 0;
        for (int i = 1; i < size-1; i++) {
            if (nums[i] > nums[l] && nums[i] > nums[i+1]) {
                return i;
            }
            l = i;
        }
        return nums[size-1] > nums[0] ? size-1:0;
    }
};