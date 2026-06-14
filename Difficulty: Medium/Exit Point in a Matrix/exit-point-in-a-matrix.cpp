class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int move = 0, i = 0, j = 0;
        while(i >= 0 && i < n && j >= 0 && j < m) {
            if(mat[i][j] == 1) {
                mat[i][j] = 0;
                move = (move + 1) % 4;
            }
            i += dx[move];
            j += dy[move];
        }
        return {i - dx[move], j - dy[move]};
    }
};

