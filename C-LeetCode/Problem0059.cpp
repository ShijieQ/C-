#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        ans[0][0] = 1;
        int i = 0, j = 0, count = 1;
        while (count < n*n) {
            while (j+1 < n && ans[i][j+1] == 0) {
                ans[i][++j] = ++count;
            }
            while (i+1 < n && ans[i+1][j] == 0) {
                ans[++i][j] = ++count;
            }
            while (j-1 >= 0 && ans[i][j-1] == 0) {
                ans[i][--j] = ++count;
            }
            while (i-1 >= 0 && ans[i-1][j] == 0) {
                ans[--i][j] = ++count;
            }
        }
        return ans;
    }
};