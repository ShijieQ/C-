#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
        int len1 = nums1.size(), len2 = nums2.size(); 
        int cnt = -1;
        bool flag = (len1 + len2) & 1;
        double ans = 0;
        while (l < len1 || r < len2) {
            if ((l < len1 && r < len2 && nums1[l] < nums2[r]) || (l < len1 && r == len2)) {
                l++;
                cnt++;
                if (cnt == (len1 + len2)/2 || cnt == (len1 + len2 - 1)/2) {
                    ans += nums1[l - 1];
                    if (flag) {
                        ans *= 2;
                    }
                }
            }
            else {
                r++;
                cnt++;
                if (cnt == (len1 + len2)/2 || cnt == (len1 + len2 - 1)/2) {
                    ans += nums2[r - 1];
                    if (flag) {
                        ans *= 2;
                    }
                }
            }
        }
        ans /= 2;
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    double ans = test.findMedianSortedArrays(a, b);
    cout<<ans<<endl;
    // ans = test.findMedianSortedArrays({1, 2}, {3, 4});
    // cout<<ans<<endl;
    return 0;
}