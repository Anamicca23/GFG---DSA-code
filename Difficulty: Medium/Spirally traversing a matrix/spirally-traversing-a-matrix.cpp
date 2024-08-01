//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n=matrix.size(), m=matrix[0].size();
        int left=0, right=m-1, up=0, down=n-1;
        vector<int>ans;
        
        while(left<=right && up<=down){
            for(int col=left; col<=right && up<=down; col++){
                ans.push_back(matrix[up][col]);
            }
            up++;
            
            for(int row=up; row<=down && left<=right; row++){
                ans.push_back(matrix[row][right]);
            }
            right--;
            
            for(int col=right; col>=left && up<=down; col--){
                ans.push_back(matrix[down][col]);
            }
            down--;
            
            for(int row=down; row>=up && left<=right; row--){
                ans.push_back(matrix[row][left]);
            }
            left++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends