class Solution {
	public:
	int solve(
	int i,
	int arrayIndex,
	vector<int>& a,
	vector<int>& b,
	unordered_map<int, int>& am,
	unordered_map<int, int>& bm,
	vector<vector<int>> & dp
	)
	{
		vector<int> *ptr;
		if (arrayIndex == 0)
			ptr = &a;
		else
			ptr = &b;
		
		if (ptr->size() <= i) {
			return 0;
		}
		
		if (dp[arrayIndex][i] != -1)
			return dp[arrayIndex][i];
		
		int currEle = (*ptr)[i];
		
		bool common = am.find(currEle) != am.end() && bm.find(currEle) != bm.end();
		if (common) {
			int nextIndex = am[currEle] + 1;
			int l = solve(nextIndex, 0, a, b, am, bm, dp);
			
			nextIndex = bm[currEle] + 1;
			int r = solve(nextIndex, 1, a, b, am, bm, dp);
			
			dp[arrayIndex][i] = max(l, r);
		}
		else {
			dp[arrayIndex][i] = solve(i + 1, arrayIndex, a, b, am, bm, dp);
		}
		
		return dp[arrayIndex][i] += currEle;
	}
	
	int maxPathSum(vector<int> &a, vector<int> &b) {
		int n = a.size(), m = b.size();
		unordered_map<int, int> am, bm;
		for (int i = 0; i<n; i++)
			am[a[i]] = i;
		for (int i = 0; i<m; i++)
			bm[b[i]] = i;
		vector<vector<int>> dp(2, vector<int>(max(n, m), -1));
		int l = solve(0, 0, a, b, am, bm, dp);
		int r = solve(0, 1, a, b, am, bm, dp);
		return max(l, r);
	}
};