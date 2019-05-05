#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long int ans = 0;
        int i = 0, t = 1;
        int len = str.length();
        while (i < len && !isdigit(str[i])) {
            if (str[i] != '-' && str[i] != ' ' && str[i] != '+') {
                return ans;
            }
            if (str[i] == '-' || str[i] == '+') {
                t = (str[i] == '-' ? -1:1);
                i++;
                break;
            }
            i++;
        }
        while (i < len && isdigit(str[i])) {
            ans = ans*10 + str[i] - '0';
            if (ans*t > 2147483647) {
                return 2147483647;
            }
            if (ans*t < -2147483648) {
                return -2147483648;
            }
            i++;
        }
        ans = ans*t;
        if (ans > 2147483647) {
            ans = 2147483647;
        }
        if (ans < -2147483648) {
            ans = -2147483648;
        }
        return ans;
    }
};

int main() {
    Solution test;
    int ans = test.myAtoi("+1");
    cout<<ans<<endl;
    ans = test.myAtoi("- 234");
    cout<<ans<<endl;
    return 0;
}