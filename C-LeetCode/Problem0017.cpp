#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    vector<int> num;
    int siz;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        siz = digits.size();
        if (!siz) {
            return ans;
        }
        for (int i = 0; i < siz; i++) {
            num.push_back(digits[i] - '0');
        }
        DFS(0, "");
        return ans;
    }

    void DFS(int step, string s) {
        if (step == siz) {
            ans.push_back(s);
            return ;
        }
        for (int i = 0; i < a[num[step]].size(); i++) {
            s += a[num[step]][i];
            DFS(step + 1, s);
            s.erase(s.end() - 1);
        }
    }
};

int main() {
    Solution test;
    vector<string> s = test.letterCombinations("23");
    for (int i = 0; i < s.size(); i++) {
        cout<<s[i]<<endl;
    }
    return 0;
}