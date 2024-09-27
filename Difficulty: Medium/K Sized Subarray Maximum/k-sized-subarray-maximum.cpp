//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        deque<int> de;  // Stores indices
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (!de.empty() && de.front() == i - k) de.pop_front(); // Remove out-of-window elements
            while (!de.empty() && arr[de.back()] <= arr[i]) de.pop_back(); // Remove smaller elements
            de.push_back(i); // Push current index
            if (i >= k - 1) ans.push_back(arr[de.front()]); // Append max of current window
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
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends