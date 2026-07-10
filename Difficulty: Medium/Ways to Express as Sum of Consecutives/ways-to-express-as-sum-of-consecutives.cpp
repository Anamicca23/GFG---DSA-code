class Solution {
public:
    int getCount(int n) {
        int cntOdd = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int d1 = i;
                int d2 = n / i;
                if (d1 % 2 == 1)
                    cntOdd++;
                if (d2 != d1 && d2 % 2 == 1)
                    cntOdd++;
            }
        }
        return cntOdd - 1;
    }
};