#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        unordered_map<char, char> vis = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        int siz = s.size();
        for (int i = 0; i < siz; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                check.push(s[i]);
            }
            else if (!check.empty() && vis[check.top()] == s[i]) {
                check.pop();
            }
            else {
                return false;
            }
        }
        return check.empty();
    }
};