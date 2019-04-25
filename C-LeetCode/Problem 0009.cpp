#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<char> ans;
        while (x) {
            ans.push_back(x%10);
            x /= 10;
        }
        int siz = ans.size();
        for (int i = 0; i < siz/2; i++) {
            if (ans[i] != ans[siz - i - 1]) {
                return false;
            }
        }
        return true;
    }
};