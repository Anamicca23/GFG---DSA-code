class Solution {
  public:
    int bins(const vector<int>& arr, int mult, int target)
    {
        const int n = arr.size();
        if(n <= 0) return 0;
        int left = 0, right = n - 1, out = n;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if((arr[mid] * mult) > target)
            {
                out = min(out, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return out;
    }
    
    int countNumbers(int n) {
        int out = 0;
        int sqrt_n = (int) sqrt(n);
        vector<int> sieve(sqrt_n + 1, 0);
        vector<int> primes;
        for(int i = 2; i <= sqrt_n; i++)
        {
            if(sieve[i] == 0)
            {
                out += bins(primes, i, sqrt_n);
                primes.push_back(i);
                for(int j = i << 1; j <= sqrt_n; j += i)
                {
                    sieve[j] = 1;
                }
            }
        }
        return out + bins(primes, 1, (int)sqrt(sqrt(sqrt(n))));
    }
};