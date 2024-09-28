//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int helper(int i, int k, vector<int> &arr, vector<int> &dp)
{
    if (i == arr.size() - 1)
        return 0;

    if (i >= arr.size())
        return 1e9;

    if (dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    for (int j = i + 1; j <= i + k; j++)
    {
        int value = helper(j, k, arr, dp);
        if (j < arr.size())
            value += abs(arr[j] - arr[i]);
        mini = min(mini, value);
    }

    return dp[i] = mini;
}

int minimizeCost(int k, vector<int> &arr)
{
    // Code here
    int n = arr.size();
    vector<int> dp(n, -1);
    return helper(0, k, arr, dp);
}
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends