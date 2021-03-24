class Solution {
private:
    int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int r = i+offset[k][0], c = j+offset[k][1];
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0' || vis[r][c]) {
                continue;
            }
            dfs(grid, r, c, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return ans;
    }
};