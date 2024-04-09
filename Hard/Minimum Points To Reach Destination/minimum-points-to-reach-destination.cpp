//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

 public:
 int minPoints(int M, int N, vector<vector<int>> points) { 
      vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[M - 1][N - 1] = max(1, 1 - points[M - 1][N - 1]);
        for (int i = M - 2; i >= 0; --i) {
            dp[i][N - 1] = max(1, dp[i + 1][N - 1] - points[i][N - 1]);
        }
        for (int j = N - 2; j >= 0; --j) {
            dp[M - 1][j] = max(1, dp[M - 1][j + 1] - points[M - 1][j]);
        }
        for (int i = M - 2; i >= 0; --i) {
            for (int j = N - 2; j >= 0; --j) {
                int minPointsRequired = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, minPointsRequired - points[i][j]);
            }
        }
        return dp[0][0];
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends