class Solution {
	public:
	int maxArea(vector<vector<int>> & mat) {
		int n = mat.size();
		int m = mat[0].size();
		vector<vector<int>> v(n, vector<int>(m));
		for (int i = 0; i<m; i++) {
			int cnt = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (mat[j][i] == 1) {
					cnt++;
				}
				else {
					cnt = 0;
				}
				v[j][i] = cnt;
			}
		}
		int maxi = INT_MIN;
		for (int i = 0; i<n; i++) {
			vector<int> w;
			for (int j = 0; j<m; j++) {
				if (v[i][j] == 0) {
					continue;
				}
				else {
					w.push_back(v[i][j]);
				}
			}
			sort(w.begin(), w.end());
			int n1 = w.size();
			for (int i = 0; i<w.size(); i++) {
				maxi = max(maxi, (n1 - i)*w[i]);
			}
		}
		if (maxi == INT_MIN) {
			return 0;
		}
		return maxi;
	}
};
