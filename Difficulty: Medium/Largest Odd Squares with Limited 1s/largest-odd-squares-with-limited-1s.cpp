class Solution {
	public:
	int get(int r, int c, int k, vector<vector<int>> & pre) {
		int top = r - k ;
		int bottom = r + k ;
		int left = c - k ;
		int right = c + k ;
		int sum = pre[bottom][right] ;
		if (top > 0)
			sum -= pre[top - 1][right] ;
		if (left > 0)
			sum -= pre[bottom][left - 1] ;
		if (top > 0 && left > 0)
			sum += pre[top - 1][left - 1] ;
		return sum ;
	}
	vector<int> largestSquare(vector<vector<int>> & mat, vector<vector<int>> & queries,
	int k) {
		// code here
		vector<vector<int>> pre = mat ;
		int n = mat.size() ;
		int m = mat[0].size() ;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0) {
					pre[i][j] += pre[i - 1][j] ;
				}
				if (j > 0) {
					pre[i][j] += pre[i][j - 1] ;
				}
				if (i > 0 && j > 0) {
					pre[i][j] -= pre[i - 1][j - 1] ;
				}
			}
		}
		vector<int> ans ;
		for (int i = 0; i < queries.size(); i++) {
			int r = queries[i][0] ;
			int c = queries[i][1] ;
			int radius = min(r, min(c, min(n - 1-r, m - 1-c))) ;
			int low = 0 ;
			int high = radius ;
			int temp = -1 ;
			while (low <= high) {
				int mid = (low + high)/2 ;
				int one = get(r, c, mid, pre) ;
				if (one <= k) {
					temp = mid ;
					low = mid + 1 ;
				} else {
					high = mid - 1 ;
				}
			}
			if (temp != -1)
				ans.push_back(2*temp + 1) ;
			else
				ans.push_back(-1) ;
		}
		return ans ;
	}
};
