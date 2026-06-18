class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), total = 0;
        vector<bool> up(n, false), left(m, false),
        right(m, false), down(n, false);
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    if(left[i]) total++;
                    if(up[j]) total++;
                }
                if(mat[i][j] == 1) {
                    left[i] = true;
                    up[j]   = true;
                }
                if(mat[m-i-1][n-j-1] == 0) {
                    if(right[m-i-1]) total++;
                    if(down[n-j-1]) total++;
                }
                if(mat[m-i-1][n-j-1] == 1) {
                    right[m-i-1] = true;
                    down[n-j-1] = true;
                }
            }
        } return total;
    }
};
