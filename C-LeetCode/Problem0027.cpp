#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int siz = nums.size();
        int cnt = 0;
        for (int i = 0; i < siz; i++) {
            if (nums[i] == val) {
                cnt++;
            }
            else {
                nums[i - cnt] = nums[i];
            }
        }
        return siz - cnt;
    }
};