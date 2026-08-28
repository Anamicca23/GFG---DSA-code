class Solution {
public:
    vector<vector<int>> vec;
    int mod = 1e9 + 7;
    int solve(int idx, string& s, int n, int carry) {
        if (idx >= s.size())
            return carry ? 0 : 1;
        if (vec[carry][idx] != -1)
            return vec[carry][idx];
        int res = solve(idx + 1, s, n, carry);
        int num = (carry * 10) + (int)(s[idx] - '0');
        res = (res + solve(idx + 1, s, n, num % n)) % mod;
        return vec[carry][idx] = res;
    }
    int countSubsequences(string& s, int n) {
        vec = vector<vector<int>>(n + 1, vector<int>(s.size() + 1, -1));
        int res = solve(0, s, n, 0);
        return (res - 1 + mod) % mod;
    }
};