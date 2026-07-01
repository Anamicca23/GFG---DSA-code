class Solution {
	public:
	int maxSumSubarray(vector<int> &arr) {
		const int size = arr.size();
		int ans = arr[0];
		int prevNoDelete = arr[0];
		int prevOneDelete = -1e9;
		
		for (int i = 1; i < size; i++) {
			int currNoDelete = max(prevNoDelete + arr[i], arr[i]);
			int currOneDelete = max(prevNoDelete, prevOneDelete + arr[i]);
			ans = max({ans, currNoDelete, currOneDelete});
			prevNoDelete = currNoDelete;
			prevOneDelete = currOneDelete;
		}
		return ans;
	}
};
