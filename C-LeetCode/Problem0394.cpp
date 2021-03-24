class Solution {
public:

    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    string getString(string s, int n) {
        string temp = s;
        for (int i = 0; i < n-1; i++) {
            s += temp;
        }
        return s;
    }

    string decodeString(string s) {
        stack<char> stack;
        int i = 0, len = s.length();
        while (i < len) {
            if (s[i] == ']') {
                string temp = "";
                while (!stack.empty() && stack.top() != '[') {
                    temp += stack.top();
                    stack.pop();
                }
                stack.pop();
                int num = 0;
                int m = 1;
                while (!stack.empty() && isNumber(stack.top())) {
                    char ch = stack.top();
                    num += (ch - '0')*m;
                    m *= 10;
                    stack.pop();
                }
                // cout<<"num = "<<num<<", temp = "<<temp<<endl;
                string now = getString(temp, num);
                reverse(now.begin(), now.end());
                for (auto &ch : now) {
                    stack.push(ch);
                }
            }
            else {
                stack.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while (!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};