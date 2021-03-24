class Solution {
private:
    bool isOperator(string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int toInt(string &s) {
        int ans = 0, len = s.length(), flag = 0;
        if (s[0] == '-') {
            flag = 1;
        }
        for (int i = flag; i < len; i++) {
            ans *= 10;
            ans += (s[i]-'0');
        }
        return flag == 1 ? -ans:ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int i = 0, len = tokens.size();
        while (i < len) {
            if (isOperator(tokens[i])) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                // cout<<"a = "<<a<<", b = "<<b<<", token = "<<tokens[i]<<endl;
                if (tokens[i] == "+") {
                    s.push(b+a);
                }
                else if (tokens[i] == "-") {
                    s.push(b-a);
                }
                else if (tokens[i] == "*") {
                    s.push(b*a);
                }
                else if (tokens[i] == "/") {
                    s.push(b/a);
                }
            }
            else {
                s.push(toInt(tokens[i]));
            }
            i++;
        }
        return s.top();
    }
};