class Solution {
public:
    int countSubsets(vector<int>& arr) {
        const int MOD = 1000000007;

        // 1. Count frequencies in O(N)
        int freq[31] = {0};
        for (int x : arr) {
            freq[x]++;
        }

        // 2. Hardcoded bitmasks for primes up to 30. -1 means the number has a square factor.
        // Primes represented: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
        const int masks[31] = {
            0, 0, 1, 2, -1, 4, 3, 8, -1, -1, 5, 16, -1, 32, 9, 6,
            -1, 64, -1, 128, -1, 10, 17, 256, -1, -1, 33, -1, -1, 512, 7
        };

        // 3. DP array using fast stack memory
        int dp[1024] = {0};
        dp[0] = 1;

        // DP state transitions: O(30 * 1024)
        for (int x = 2; x <= 30; x++) {
            if (masks[x] == -1 || freq[x] == 0) continue;
            
            int m_x = masks[x];
            int count = freq[x];
            
            for (int m = 1023; m >= 0; m--) {
                // If there's no overlapping prime factors
                if ((m & m_x) == 0) {
                    dp[m | m_x] = (dp[m | m_x] + 1LL * dp[m] * count) % MOD;
                }
            }
        }

        // 4. Sum valid combinations (ignoring dp[0] which is the empty set)
        long long ans = 0;
        for (int m = 1; m < 1024; m++) {
            ans = (ans + dp[m]) % MOD;
        }

        // 5. Binary Exponentiation for 2^freq[1] in O(log N) time
        long long mul = 1;
        long long base = 2;
        int exp = freq[1];
        while (exp > 0) {
            if (exp % 2 == 1) mul = (mul * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return (ans * mul) % MOD;
    }
};