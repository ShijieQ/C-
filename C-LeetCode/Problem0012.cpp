#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> s = {{1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}, 
                                        {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
                                        {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"},
                                        {1000, "M"}, {2000, "MM"}, {3000, "MMM"}};
        int a[] = {1000, 100, 10, 1};
        string ans = "";
        for (int i = 0; i < 4; i++) {
            if (num/a[i]*a[i] != 0) {
                ans += s[num/a[i]*a[i]];
            }
            num %= a[i];
        }
        return ans;
    }
};

int main() {
    Solution test;
    string ans = test.intToRoman(3);
    cout<<ans<<endl;
    ans = test.intToRoman(4);
    cout<<ans<<endl;
    ans = test.intToRoman(9);
    cout<<ans<<endl;
    ans = test.intToRoman(58);
    cout<<ans<<endl;
    ans = test.intToRoman(1994);
    cout<<ans<<endl;
    return 0;
}