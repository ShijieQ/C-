#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int siz = strs.size();
        string ans = "";
        if (!siz) {
            return ans;
        }
        int minlen = 2147483647;
        for (int i = 0; i < siz; i++) {
            if (strs[i].length() < minlen) {
                minlen = strs[i].length();
            }
        }
        for (int i = 0; i < minlen; i++) {
            bool flag = 1;
            char check = strs[0][i];
            for (int j = 1; j < siz; j++) {
                if (check != strs[j][i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans += check;
            }
            else {
                break;
            }
        }
        return ans;
    }
};