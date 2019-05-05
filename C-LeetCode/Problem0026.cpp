#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int siz = nums.size();
        if (!siz) {
            return 0;
        }
        int ans = 1;
        for (int i = 1, j = 1; i < siz; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
                ans++;
            }
        }
        return ans;
    }
};

class Solution_better {
    public:
    int removeDuplicates(vector<int>& nums) {
        int siz = nums.size();
        int cnt = 0;
        for (int i = 1; i < siz; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            }
            else {
                nums[i - cnt] = nums[i];
            }
        }
        return siz - cnt;
    }
};