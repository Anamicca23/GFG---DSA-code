//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            int c = arr[i]; 
            int left = 0, right = n - 1;

            while (left < right) {
                if (left == i) {
                    left++; 
                    continue;
                }
                if (right == i) {
                    right--; 
                    continue;
                }
                int sum = arr[left] + arr[right];
                if (sum == c) {
                    return true; 
                } else if (sum < c) {
                    left++; 
                } else {
                    right--; 
                }
            }
        }
        return false; 
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends