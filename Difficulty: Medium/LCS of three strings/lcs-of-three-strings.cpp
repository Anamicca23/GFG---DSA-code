class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));

    function<int(int, int, int)> Solve = [&](int i, int j, int k) -> int {
        if (i >= n1 || j >= n2 || k >= n3) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        if (s1[i] == s2[j] && s2[j] == s3[k])
            return dp[i][j][k] = 1 + Solve(i + 1, j + 1, k + 1);
        else
            return dp[i][j][k] = max({
                Solve(i + 1, j, k),
                Solve(i, j + 1, k),
                Solve(i, j, k + 1)
            });
    };

    return Solve(0, 0, 0);
}
};
