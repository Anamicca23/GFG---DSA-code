//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat) {
        int n = mat.size();
        vector<int> res;
        int diag = 0;
        while(diag < 2 * n - 1) {
            if(diag & 1) {
                int r = 0, c = diag;
                while(r < n && c >= 0) {
                    if(c < n) res.push_back(mat[r][c]);
                    r++, c--;
                }
            } else {
                int r = diag, c = 0;
                while(r >= 0 && c < n) {
                    if(r < n) res.push_back(mat[r][c]);
                    r--, c++;
                }
            }
            diag++;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends