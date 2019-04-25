#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<vector<char>> temp(numRows);
        bool flag = 1;
        int len = s.length();
        int i = 0, l = 0;
        while (i < len) {
            temp[l].push_back(s[i]);
            if (l == numRows - 1) {
                flag = 0;
            }
            if (l == 0) {
                flag = 1;
            }
            if (flag) {
                l++, i++;
            }
            else {
                l--, i++;
            }
        }
        string ans = "";
        for (i = 0; i < numRows; i++) {
            int siz = temp[i].size();
            for (int j = 0; j < siz; j++) {
                ans += temp[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    string s = test.convert("AB", 1);
    cout<<s<<endl;
    return 0;
}