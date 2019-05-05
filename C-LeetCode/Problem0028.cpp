#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int lens = haystack.length();
        int len = needle.length();
        for (int i = 0; i <= lens - len; i++) {
            if (haystack.substr(i, len) == needle) {
                return i;
            }
        }
        return -1;
    }
};