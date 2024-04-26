//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<vector<int>>moves = {{0,1},{1,0},{0,-1},{-1,0}};
        int i = 0, j = 0, p = 0;
        while(true){
            if(matrix[i][j]){
                p++;
                matrix[i][j] = 0;
                i += moves[p%4][0];
                j += moves[p%4][1];
            } else {
                i += moves[p%4][0];
                j += moves[p%4][1];
            }
            if(i<0 || i>=n || j<0 || j>=m){
                return {i - moves[p%4][0], j - moves[p%4][1]};
            }
        }
        return {0,0};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends