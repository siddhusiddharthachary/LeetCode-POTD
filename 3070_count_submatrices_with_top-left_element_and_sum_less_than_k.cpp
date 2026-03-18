class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && j > 0)
                    grid[i][j] += ((grid[i - 1][j] + grid[i][j - 1]) -
                                   grid[i - 1][j - 1]);
                if (grid[i][j] <= k)
                    ans++;
            }
        }
        return ans;
    }
};
