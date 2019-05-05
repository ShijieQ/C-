#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(int now, int pre, int target) {
        if (abs(now - target) < abs(pre - target)) {
            return now;
        }
        else {
            return pre;
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int siz = nums.size();
        int ans = 0x3f3f3f3f;
        bool flag = 0;
        for (int i = 0; !flag && i < siz - 2; i++) {
            int l = i + 1, r = siz - 1;
            while (l < r) {
                int now = nums[i] + nums[l] + nums[r];
                ans = check(now, ans, target);
                if (now > target) {
                    r--;
                }
                else if(now < target){
                    l++;
                }
                else{
                    flag = 1;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> temp = {1, 1, -1, -1, 3};
    cout<<(test.threeSumClosest(temp, 3))<<endl;
    return 0;
}