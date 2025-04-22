//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
         int n=arr.size();
        int ans=arr[0];
        for(int i=1; i<n; i++){
            ans^=arr[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findUnique(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends