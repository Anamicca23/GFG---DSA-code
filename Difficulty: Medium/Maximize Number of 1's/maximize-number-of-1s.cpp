//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0, maxLength = 0, zeroCount = 0;
    
        // Sliding window
        while (right < arr.size()) {
            // Expand the window and count zeros
            if (arr[right] == 0) {
                zeroCount++;
            }
    
            // If zero count exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
    
            // Update the maximum length of subarray
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
    
        return maxLength;
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends