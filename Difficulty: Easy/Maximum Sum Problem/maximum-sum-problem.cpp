class Solution {
	public:
	int maxSum(int n) {
		// Base Case
		if (n == 0) {
			return 0;
		}
		return max(n, maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
	}
};
