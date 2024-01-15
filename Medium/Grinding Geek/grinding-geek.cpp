//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    int dp[1001][1001]; // Memoization table to store computed results for dynamic programming.

    int func(int ind, int total, vector<int>& cost, int n) {
        // Recursive function to find the maximum number of courses within a given budget.
        if (ind == n) return 0; // Base case: If the index reaches the total number of courses, return 0.

        if (dp[ind][total] != -1) return dp[ind][total]; // If the result is already memoized, return the stored value.

        int notpick = func(ind + 1, total, cost, n); // Explore the not taken path.

        int pick = 0;
        if (cost[ind] <= total) // If the remaining budget allows for taking the course.
            pick = 1 + func(ind + 1, total - cost[ind] + (cost[ind] * 9) / 10, cost, n); // Explore the taken path.

        // Store the maximum value obtained by either taking or not taking the current course.
        return dp[ind][total] = max(pick, notpick);
    }

    int max_courses(int n, int total, vector<int>& cost) {
        memset(dp, -1, sizeof(dp)); // Initialize the memoization table with -1.
        return func(0, total, cost, n); // Call the recursive function with initial parameters.
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends