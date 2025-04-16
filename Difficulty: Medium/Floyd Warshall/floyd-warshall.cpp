//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
     void floydWarshall(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        for(int via=0;via<n;via++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if( grid[i][via] != 1e8 and grid[via][j] != 1e8 )
                        grid[i][j]=min(grid[i][j],grid[i][via] + grid[via][j]);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends