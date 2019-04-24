#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        int mid = len1 + len2;
        bool status;
        if (nums1[0] < nums2[0]) {
            status = 0;
        }     
        else {
            status = 1;
        }
        while (l < len1 || r < len2) {
            if (status) {
                if (l + 1 < len1 && nums1[l + 1] < nums2[r]) {
                    status
                }
            }
        }
    }
};