class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        vector<int>ans;
        int n = mat.size();
        for(int k=0; k<n; k++)
        {
            int i=0, j=k;
            while(i<n && j<n && i*j>=0)
            {
                ans.push_back(mat[i][j]);
                i++, j--;
            }
        }
        for(int k=1; k<n; k++)
        {
            int i=k, j=n-1;
            while(i<n && j<n && i*j>=0)
            {
                ans.push_back(mat[i][j]);
                i++, j--;
            }
        }
        return ans;
    }
};