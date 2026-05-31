class Solution {
	public:
	bool isSumOfConsecutive(int n) {
		while (n>1) {
			if (n &1)return 1;
			n = n>> 1;
		}
		return false;
	}
 };
