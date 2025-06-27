class Solution {
public:
    int dp[4][3][501];

    int fun(int i, int j, int n, const char mat[4][3]) {
        if (i < 0 || i > 3 || j < 0 || j > 2 || mat[i][j] == '*' || mat[i][j] == '#')
            return 0;
        if (n == 1)
            return 1;
        if (dp[i][j][n] != -1)
            return dp[i][j][n];

        int moves[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int res = 0;
        for (int k = 0; k < 5; ++k)
            res += fun(i + moves[k][0], j + moves[k][1], n - 1, mat);

        return dp[i][j][n] = res;
    }

    int getCount(int n) {
        if (n <= 0) return 0;

        const char mat[4][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
            {'*', '0', '#'}
        };

        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                if (mat[i][j] != '*' && mat[i][j] != '#')
                    ans += fun(i, j, n, mat);

        return ans;
    }
};
