class Solution {
public:
    string reverseWords(string s) {
        int siz = s.size();
        string now = "";
        stack<string> stack;
        for (int i = 0; i < siz; i++) {
            if (s[i] == ' ') {
                if (now != "") {
                    stack.push(now);
                }
                now = "";
            }
            else {
                now += s[i];
            }
        }
        if (now != "") {
            stack.push(now);
        }
        string ans = "";
        if (stack.size() == 1) {
            return stack.top();
        }
        else {
            ans += stack.top();
            stack.pop();
        }
        while (!stack.empty()) {
            ans += " ";
            ans += stack.top();
            stack.pop();
        }
        return ans;
    }
};