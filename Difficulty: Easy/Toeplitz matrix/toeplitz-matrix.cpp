class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(mat[i][j] != mat[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};