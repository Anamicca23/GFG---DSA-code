class Solution {
  public:

    // Computes the Möbius function up to 'n'
    void computeMobius(int n, vector<int>& mu) {
        vector<int> is_prime(n + 1, 1);
        mu[0] = 0;
        mu[1] = 1;

        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    is_prime[j] = 0;
                }
                // Not square-free
                for (int j = i * i; j <= n; j += i * i) {
                    mu[j] = 0;
                }
            }
        }
    }

    // Builds frequency array for values in 'arr'
    void buildFre(vector<int>& arr, vector<int>& freq) {
        for (int x : arr)
            freq[x]++;
    }

    // For each k, computes how many numbers in arr are divisible by k
    void computeDivCnt(int maxVal, vector<int>& freq, vector<int>& d) {
        for (int k = 1; k <= maxVal; ++k)
            for (int j = k; j <= maxVal; j += k)
                d[k] += freq[j];
    }

    // logic to count coprime pairs using
    // Möbius and Inclusion-Exclusion
    int cntCoprime(vector<int>& arr) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal + 1, 0), d(maxVal + 1, 0), mu(maxVal + 1, 1);

        buildFre(arr, freq);
        computeDivCnt(maxVal, freq, d);
        computeMobius(maxVal, mu);

        int result = 0;
        for (int k = 1; k <= maxVal; ++k) {
            if (mu[k] == 0 || d[k] < 2)
                continue;

            int pairs = d[k] * (d[k] - 1) / 2;
            result += mu[k] * pairs;
        }

        return result;
    }
};