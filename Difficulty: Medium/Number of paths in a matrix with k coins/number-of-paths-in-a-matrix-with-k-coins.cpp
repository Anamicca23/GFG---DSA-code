class Solution {
public:
    int n, m;
    int dp[101][101][101]; // dp[row][col][coins]

    int solve(int i, int j, int k, vector<vector<int>>& mat) {
        if (i >= n || j >= m || k < 0) return 0;

        // subtract current cell value
        k -= mat[i][j];
        if (k < 0) return 0;

        // reached destination
        if (i == n - 1 && j == m - 1) 
            return (k == 0);

        // memo check
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // move down or right
        int down = solve(i + 1, j, k, mat);
        int right = solve(i, j + 1, k, mat);

        return dp[i][j][k] = down + right;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, mat);
    }
};