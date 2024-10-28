//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        vector<int> nondup;
        unordered_set<int> seen;

        for (int num : arr) {
            if (seen.find(num) == seen.end()) { // If `num` is not in `seen`
                nondup.push_back(num);          // Add it to `nondup`
                seen.insert(num);               // Mark `num` as seen
            }
        }
        return nondup;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends