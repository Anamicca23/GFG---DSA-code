//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int dp[21][21][21] ;
        
        int LCS( string A, string B, string C, int i , int j , int k )
        {
            if( i == A.size() or j == B.size() or k == C.size()) return 0 ;
            
            if( dp[i][j][k] != -1 ) return dp[i][j][k] ;
            
            int ans = 0 ;
            
            if( A[i] == B[j] && B[j] == C[k] )
            {
                return dp[i][j][k]  =  1 + LCS( A , B , C , i+1 , j+1 , k+1 ) ;
            }
            else{
                
                return dp[i][j][k]  = max( LCS( A , B , C , i+1 , j , k ) , max( LCS( A , B , C , i , j + 1 , k ) , LCS( A , B , C , i , j , k + 1 ) ) ) ;
                 
            }
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            memset( dp , -1 , sizeof(dp) ) ;
            return LCS( A , B  , C , 0 , 0 , 0 ) ;
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends