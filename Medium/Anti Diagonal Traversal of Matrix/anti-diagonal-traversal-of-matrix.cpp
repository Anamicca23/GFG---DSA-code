//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> ans;
        int col=matrix[0].size(), row=matrix.size();
            for(int j=0;j<col;j++)
            {
                int k=j;
                for(int i=0;i<=j;i++)
                {
                     ans.push_back(matrix[i][k--]);
                 }
            }
            for(int i=1;i<row;i++)
            {
                int k=i;
                for(int j=(col-1);j>=i;j--)
                {
                    ans.push_back(matrix[k++][j]);
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends