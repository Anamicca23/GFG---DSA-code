//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &v) {
        int n = v.size();
        int j = 0;
        for (int i = 0; i < n ; i++) {
            if (v[i] == v[i + 1]) {
                v[i] *= 2;
                v[i + 1] = 0;
            }
            if (v[i] != 0) {
                v[j++] = v[i];
            }
        }
        while (j < n) {
            v[j++] = 0;
        }
        return v;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
