#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (!words.size()) {
            return ans;
        }
        int siz = words.size();
        int lenword = words[0].size(), lens = s.length(), lenr = lenword*siz;
        unordered_map<string, int> has;
        for (string s : words) {
            has[s]++;
        }
        for (int i = 0; i + lenr - 1 < lens; i++) {
            unordered_map<string, int> check;
            bool flag = 1;
            for (int j = 0; j < siz; j++) {
                string tem = s.substr(i + j*lenword, lenword);
                check[tem]++;
                if (!has[tem] || check[tem] > has[tem]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = test.findSubstring(s, words);
    int siz = ans.size();
    cout<<"siz = "<<siz<<endl;
    for (int i = 0; i < siz; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}