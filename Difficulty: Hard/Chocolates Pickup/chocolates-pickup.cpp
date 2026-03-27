class Solution {
  public:
    int maxChocolate(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> curr(m, vector<int>(m, 0)), next(m, vector<int>(m, 0));
        for(int r = n - 1; r >= 0; r--) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = 0; c2 < m; c2++) {
                    curr[c1][c2] = -1e9;
                    for(int u = -1; u <= 1; u++) {
                        for(int v = -1; v <= 1; v++) {
                            if(c1 + u < 0 || c1 + u >= m || c2 + v < 0 || c2 + v >= m) continue;
                            curr[c1][c2] = max(curr[c1][c2], grid[r][c1] + ((c1 == c2) ? 0 : grid[r][c2]) + next[c1 + u][c2 + v]);
                        }
                    }
                }
            }
            next = curr;
        }
        return next[0][m - 1];
    }
};