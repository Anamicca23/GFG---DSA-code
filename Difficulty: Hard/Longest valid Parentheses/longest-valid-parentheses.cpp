//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
       int maxLength(string& s) {
        // code here
          int left = 0;
        int right = 0;
        int max = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                max = max>right * 2?max:right * 2;
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;

        for (int i = s.size(); i > 0; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }
            if (left == right) {
                max = max>right * 2?max:right * 2;
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends