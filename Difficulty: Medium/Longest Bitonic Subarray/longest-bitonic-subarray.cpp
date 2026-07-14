class Solution {
	public:
	int bitonic(vector<int> &arr) {
		const int size = arr.size();
		if (size == 1) {
			return 1;
		}
		int ans = 1;
		int i = 0;
		int j = 1;
		bool inc = (arr[j] >= arr[i]);
		int same = -1;
		while (j < size) {
			if (inc) {
				if (arr[j - 1] > arr[j]) {
					inc = false;
				}
			}
			else {
				if (same == -1 && arr[j - 1] == arr[j]) {
					same = j - 1;
				} else if (same != -1 && arr[j - 1] > arr[j]) {
					same = -1;
				} else if (arr[j - 1] < arr[j]) {
					ans = max(ans, j - i);
					i = (same != -1) ? same : j - 1;
					same = -1;
					inc = true;
				}
			}
			j++;
		}
		ans = max(ans, j - i);
		
		return ans;
	}
	
};
