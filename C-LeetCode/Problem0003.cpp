#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> temp;
        vector<bool> vis(256);
        int len = s.length();
        int i = 0;
        int ans = 0;
        while (i < len) {
            if (!vis[s[i]]) {
                vis[s[i]] = 1;
                temp.push_back(s[i]);
                int siz = temp.size();
                ans = max(ans, siz);
                i++;
            }
            else {
                if (!temp.empty()) {
                    vis[temp.front()] = 0;
                    temp.pop_front();
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    while(1){
        string s;
        cin>>s;
        int ans = test.lengthOfLongestSubstring(s);
        cout<<ans<<endl;
    }
}