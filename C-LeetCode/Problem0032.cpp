#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), ans = 0;
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }
        if (st.empty()) {
            ans = len;
        }
        else {
            int l = len;
            while (!st.empty()) {
                ans = max(ans, l - st.top() - 1);
                l = st.top();
                st.pop();
            }
            ans = max(ans, l);
        }
        return ans;
    }
};

int main() {
    Solution test;
    int ans = test.longestValidParentheses("(()");
    cout<<ans<<endl;
    ans = test.longestValidParentheses(")()())");
    cout<<ans<<endl;
    ans = test.longestValidParentheses("())");
    cout<<ans<<endl;
    return 0;
}