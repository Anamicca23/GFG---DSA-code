class Solution {
    static final int MOD = 1000000007;

    int distinctSubseq(String str) {
        int n = str.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;  // empty subsequence

        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = 1; i <= n; i++) {
            int ch = str.charAt(i - 1) - 'a';
            dp[i] = (2 * dp[i - 1]) % MOD;

            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + MOD) % MOD;
            }

            last[ch] = i - 1;
        }

        return (int) dp[n];
    }
}