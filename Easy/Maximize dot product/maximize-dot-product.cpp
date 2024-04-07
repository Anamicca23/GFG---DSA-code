//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int p = 1; p <= m; p++) {
            for(int k = p; k <= n; k++) {
                dp[p][k] = max(dp[p][k-1], dp[p-1][k-1] + a[k-1] * b[p-1]);
            }
        }
        return dp[m][n];
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends