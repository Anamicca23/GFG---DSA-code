class Solution {
	public:
	
	int lowerBound(vector<int>& positions, int target) {
		int low = 0;
		int high = positions.size();
		
		while (low < high) {
			int mid = low + (high - low) / 2;
			
			if (positions[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		
		return low;
	}
	
	vector<int> freqInRange(vector<int>& arr, vector<vector<int>> & queries) {
		
		unordered_map<int, vector<int>> mp;
		
		for (int i = 0; i < arr.size(); i++) {
			mp[arr[i]].push_back(i);
		}
		
		vector<int> ans;
		
		for (auto &q : queries) {
			int l = q[0];
			int r = q[1];
			int x = q[2];
			
			if (!mp.count(x)) {
				ans.push_back(0);
				continue;
			}
			
			vector<int>& positions = mp[x];
			
			int left = lowerBound(positions, l);
			
			int right = upper_bound(
			positions.begin(),
			positions.end(),
			r
			) - positions.begin();
			
			ans.push_back(right - left);
		}
		
		return ans;
	}
};
