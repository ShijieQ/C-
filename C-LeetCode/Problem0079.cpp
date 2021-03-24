#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& vis, int index, int i, int j) {
        // cout<<"i = "<<i<<", j = "<<j<<endl;
        if (index == word.length()-1) {
            return true;
        }
        for (int k = 0; k < 4; k++) {
            int l = i+offset[k][0], r = j+offset[k][1];
            if (l < 0 || l >= board.size() || r < 0 || r >= board[0].size() || vis[l][r]) {
                continue;
            }
            if (board[l][r] == word[index+1]) {
                vis[l][r] = true;
                bool flag = dfs(board, word, vis, index+1, l, r);
                if (flag) {
                    return true;
                }
                vis[l][r] = false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        // cout<<"m = "<<m<<", n = "<<n<<endl;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    if (dfs(board, word, vis, 0, i, j)) {
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main() {
    // Solution solution;
    // vector<vector<char>> board = {{}}
    // solution.exist()
}